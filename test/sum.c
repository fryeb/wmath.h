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

#include <stdbool.h>
#include <stdlib.h>

const size_t length = 65536;

#define TEST_SUM(t, s, max, width)                                                                 \
	UTEST(Sum, s)                                                                              \
	{                                                                                          \
		/* Generate List */                                                                \
		t##_t *data = calloc(length, sizeof(t##_t));                                       \
		t##_t expected = 0;                                                                \
		for (size_t i = 0; i < length; i++) {                                              \
			data[i] = rand();                                                          \
			expected += data[i];                                                       \
		}                                                                                  \
                                                                                                   \
		ASSERT_EQ(length % width, 0);                                                      \
		w##t##_t total = wset##s(0);                                                       \
		for (size_t i = 0; i < length; i += width) {                                       \
			w##t##_t a = wload##s##u((w##t##_t *)&data[i]);                            \
			total = wadd##s(total, a);                                                 \
		}                                                                                  \
		EXPECT_EQ(expected, whadd##s(total));                                              \
	}

TEST_SUM(uint8, u8, UINT8_MAX, WUINT8_WIDTH)
TEST_SUM(uint16, u16, UINT16_MAX, WUINT16_WIDTH)
TEST_SUM(uint32, u32, UINT32_MAX, WUINT32_WIDTH)
TEST_SUM(uint64, u64, UINT64_MAX, WUINT64_WIDTH)
TEST_SUM(int8, i8, INT8_MAX, WINT8_WIDTH)
TEST_SUM(int16, i16, INT16_MAX, WINT16_WIDTH)
TEST_SUM(int32, i32, INT32_MAX, WINT32_WIDTH)
TEST_SUM(int64, i64, INT64_MAX, WINT64_WIDTH)
// We don't use this test for float & double, since they would yeild different results due to
// floating point error

UTEST_MAIN();
