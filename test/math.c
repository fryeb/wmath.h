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

#include "../wmath.h"
#include <utest/utest.h>

size_t iterations = 65536; // How many random sets of numbers to test

// Test basic arithmetic operations
#define TEST_OP(t, s, width, opname, op)                                                           \
	UTEST(t, opname)                                                                           \
	{                                                                                          \
		/* Generate */                                                                     \
		t##_t a[width];                                                                    \
		t##_t b[width];                                                                    \
		for (size_t i = 0; i < width; i++) {                                               \
			a[i] = rand();                                                             \
			b[i] = rand();                                                             \
		}                                                                                  \
		/* Add */                                                                          \
		w##t##_t wa = wload##s##u((w##t##_t *)&a[0]);                                      \
		w##t##_t wb = wload##s##u((w##t##_t *)&b[0]);                                      \
		w##t##_t wc = w##opname##s(wa, wb);                                                \
		t##_t *c = (t##_t *)&wc;                                                           \
		/* Check */                                                                        \
		for (size_t i = 0; i < width; i++) {                                               \
			t##_t expected = a[i] op b[i];                                             \
			EXPECT_EQ(c[i], expected);                                                 \
		}                                                                                  \
	}

// int8
TEST_OP(int8, i8, WINT8_WIDTH, add, +)
TEST_OP(int8, i8, WINT8_WIDTH, sub, -)

// int16
TEST_OP(int16, i16, WINT16_WIDTH, add, +)
TEST_OP(int16, i16, WINT16_WIDTH, sub, -)
TEST_OP(int16, i16, WINT16_WIDTH, mul, *)

// int32
TEST_OP(int32, i32, WINT32_WIDTH, add, +)
TEST_OP(int32, i32, WINT32_WIDTH, sub, -)
TEST_OP(int32, i32, WINT32_WIDTH, mul, *)

// int64
TEST_OP(int64, i64, WINT64_WIDTH, add, +)
TEST_OP(int64, i64, WINT64_WIDTH, sub, -)

// uint8
TEST_OP(uint8, u8, WUINT8_WIDTH, add, +)
TEST_OP(uint8, u8, WUINT8_WIDTH, sub, -)

// uint16
TEST_OP(uint16, u16, WUINT16_WIDTH, add, +)
TEST_OP(uint16, u16, WUINT16_WIDTH, sub, -)

// uint32
TEST_OP(uint32, u32, WUINT32_WIDTH, add, +)
TEST_OP(uint32, u32, WUINT32_WIDTH, sub, -)

// uint64
TEST_OP(uint64, u64, WUINT64_WIDTH, add, +)
TEST_OP(uint64, u64, WUINT64_WIDTH, sub, -)

// float
#define float_t float
TEST_OP(float, f, WFLOAT_WIDTH, add, +)
TEST_OP(float, f, WFLOAT_WIDTH, sub, -)
TEST_OP(float, f, WFLOAT_WIDTH, mul, *)
TEST_OP(float, f, WFLOAT_WIDTH, div, /)

// double
#define double_t double
TEST_OP(double, d, WDOUBLE_WIDTH, add, +)
TEST_OP(double, d, WDOUBLE_WIDTH, sub, -)
TEST_OP(double, d, WDOUBLE_WIDTH, mul, *)
TEST_OP(double, d, WDOUBLE_WIDTH, div, /)

UTEST_MAIN();
