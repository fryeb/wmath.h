/*
	The latest version of this library is available on GitHub;
	https://github.com/fryeb/wmath.h.
*/

/*
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

#define WINLINE static inline

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifdef WMATH_FORCE_SCALAR

#define WMATH_DEFINE(t, s, T)                                                  \
	enum { W##T##_WIDTH = 1 };                                             \
	typedef t##_t w##t##_t;                                                \
	WINLINE w##t##_t wset##s(t##_t a) { return a; }                        \
	WINLINE w##t##_t wload##s(t##_t const *addr) { return *addr; }         \
	WINLINE w##t##_t wadd##s(w##t##_t a, w##t##_t b) { return a + b; }     \
	WINLINE t##_t whadd##s(w##t##_t a) { return a; };                      \
	// WINLINE w##t##_t wsub##s(w##t##_t a, w##t##_t b) { return a - b; }
	// WINLINE w##t##_t wmul##s(w##t##_t a, w##t##_t b) { return a * b; }
	// WINLINE w##t##_t wdiv##s(w##t##_t a, w##t##_t b) { return a / b; }

// WMATH_DEFINE(int8, i8, INT8)
// WMATH_DEFINE(int16, i16, INT16)
// WMATH_DEFINE(int32, i32, INT32)
// WMATH_DEFINE(int64, i64, INT64)
WMATH_DEFINE(uint8, u8, UINT8)
// WMATH_DEFINE(uint16, u16, UINT16)
// WMATH_DEFINE(uint32, u32, UINT32)
// WMATH_DEFINE(uint64, u64, UINT64)
// WMATH_DEFINE(int64, i64, INT64)
// WMATH_DEFINE(int64, i64, INT64)

#undef WMATH_DEFINE

#else /* WMATH_FORCE_SCALAR */

#include <immintrin.h>

#define WUMATH_DEFINE(n)                                                       \
	enum { WUINT##n##_WIDTH = (256) / (n) };                               \
	typedef __m256i wuint##n##_t;                                          \
	WINLINE wuint##n##_t wsetu##n(uint##n##_t a)                           \
	{                                                                      \
		return _mm256_set1_epi##n(a);                                  \
	}                                                                      \
	WINLINE wuint##n##_t wloadu##n(wuint##n##_t const *a)                  \
	{                                                                      \
		return _mm256_loadu_si256(a);                                  \
	}                                                                      \
	WINLINE wuint##n##_t waddu##n(wuint##n##_t a, wuint##n##_t b)          \
	{                                                                      \
		return _mm256_add_epi##n(a, b);                                \
	}                                                                      \
	/* TODO: Replace this with something faster */                         \
	WINLINE uint##n##_t whaddu##n(wuint##n##_t a)                          \
	{                                                                      \
		uint##n##_t data[WUINT##n##_WIDTH];                            \
		_mm256_storeu_si256((__m256i *)&data[0], a);                   \
		uint##n##_t result = 0;                                        \
		for (size_t i = 0; i < WUINT##n##_WIDTH; i++) {                \
			result += data[i];                                     \
		}                                                              \
		return result;                                                 \
	}

WUMATH_DEFINE(8)
// WUMATH_DEFINE(16)
// WUMATH_DEFINE(32)
// #define _mm256_set1_epi64 _mm256_set1_epi64x
// WUMATH_DEFINE(64)
// #undef _mm256_set1_epi64

#undef WUMATH_DEFINE

#endif /* WMATH_FORCE_SCALAR */

#ifdef __cplusplus
}
#endif

#undef WINLINE

#endif /* FRYEB_WMATH_H_INCLUDED */
