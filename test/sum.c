#include "../wmath.h"
#include <stdlib.h>
#include <utest/utest.h>

const size_t length = 65536;

#define TEST_SUM(t, s, max, width) \
	UTEST(Sum, s) \
	{\
		/* Generate List */ \
		t##_t *data = calloc(length, sizeof(t##_t));\
		t##_t expected = 0;\
		for (size_t i = 0; i < length; i++) {\
			data[i] = rand() % max;\
			expected += data[i];\
		}\
		\
		ASSERT_EQ(length % width, 0);\
		w##t##_t total = wset##s(0);\
		for (size_t i = 0; i < length; i += width) {\
			w##t##_t a = wload##s((w##t##_t*) &data[i]);\
			total = wadd##s(total, a);\
		}\
		EXPECT_EQ(expected, whadd##s(total));\
	}\

TEST_SUM(uint8, u8, UINT8_MAX, WUINT8_WIDTH)
TEST_SUM(uint16, u16, UINT16_MAX, WUINT16_WIDTH)
TEST_SUM(uint32, u32, UINT32_MAX, WUINT32_WIDTH)
TEST_SUM(uint64, u64, UINT64_MAX, WUINT64_WIDTH)

/** TODO
 * TEST_SUM(int8, i8, INT8_MAX, WINT8_WIDTH)
 * TEST_SUM(int16, i16, INT16_MAX, WINT16_WIDTH)
 * TEST_SUM(int32, i32, INT32_MAX, WINT32_WIDTH)
 * TEST_SUM(int64, i64, INT64_MAX, WINT64_WIDTH)
 */

// TODO: TEST_SUM(float, f, FLOAT_MAX, WFLOAT_WIDTH)
// TODO: TEST_SUM(double, d, DOUBLE_MAX, WDOUBLE_WIDTH)

UTEST_MAIN();
