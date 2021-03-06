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

const size_t length = 65536;

#define TEST_ZERO(t, s, max, width)                                                                \
	UTEST(zero, s)                                                                             \
	{                                                                                          \
		/* Generate List */                                                                \
		t##_t *data = calloc(length, sizeof(t##_t));                                       \
		ASSERT_EQ(length % width, 0);                                                      \
		w##t##_t total = wset##s(0);                                                       \
		for (size_t i = 0; i < length; i += width) {                                       \
			w##t##_t a = wload##s##u((w##t##_t *)&data[i]);                            \
			total = wadd##s(total, a);                                                 \
		}                                                                                  \
		EXPECT_EQ(0, whadd##s(total));                                                     \
	}

TEST_ZERO(uint8, u8, UINT8_MAX, WUINT8_WIDTH)
TEST_ZERO(uint16, u16, UINT16_MAX, WUINT16_WIDTH)
TEST_ZERO(uint32, u32, UINT32_MAX, WUINT32_WIDTH)
TEST_ZERO(uint64, u64, UINT64_MAX, WUINT64_WIDTH)

/** TODO
 * TEST_ZERO(int8, i8, INT8_MAX, WINT8_WIDTH)
 * TEST_ZERO(int16, i16, INT16_MAX, WINT16_WIDTH)
 * TEST_ZERO(int32, i32, INT32_MAX, WINT32_WIDTH)
 * TEST_ZERO(int64, i64, INT64_MAX, WINT64_WIDTH)
 * TEST_ZERO(float, f, FLOAT_MAX, WFLOAT_WIDTH)
 * TEST_ZERO(double, d, DOUBLE_MAX, WDOUBLE_WIDTH)
 */

UTEST_MAIN();
