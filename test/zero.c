#include "../wmath.h"
#include <utest/utest.h>

const size_t length = 65536;
struct Zero {
	uint8_t *u8;
	int8_t *i8;
	uint16_t *u16;
	int16_t *i16;
	uint32_t *u32;
	int32_t *i32;
	uint64_t *u64;
	int64_t *i64;
	float *f32;
	double *f64;
};

UTEST_F_SETUP(Zero)
{
	utest_fixture->u8 = calloc(length, sizeof(uint8_t));
	utest_fixture->u16 = calloc(length, sizeof(uint16_t));
	utest_fixture->u32 = calloc(length, sizeof(uint32_t));
	utest_fixture->u64 = calloc(length, sizeof(uint64_t));
	utest_fixture->i8 = calloc(length, sizeof(int8_t));
	utest_fixture->i16 = calloc(length, sizeof(int16_t));
	utest_fixture->i32 = calloc(length, sizeof(int32_t));
	utest_fixture->i64 = calloc(length, sizeof(int64_t));
	utest_fixture->f32 = calloc(length, sizeof(float));
	utest_fixture->f64 = calloc(length, sizeof(double));
}

UTEST_F_TEARDOWN(Zero)
{
	free(utest_fixture->u8);
	free(utest_fixture->u16);
	free(utest_fixture->u32);
	free(utest_fixture->u64);
	free(utest_fixture->i8);
	free(utest_fixture->i16);
	free(utest_fixture->i32);
	free(utest_fixture->i64);
	free(utest_fixture->f32);
	free(utest_fixture->f64);
}

UTEST_F(Zero, u8)
{
	ASSERT_EQ(length % WUINT8_WIDTH, 0);
	wuint8_t total = wsetu8(0);
	for (size_t i = 0; i < length; i += WUINT8_WIDTH) {
		wuint8_t a = wloadu8((wuint8_t*) &utest_fixture->u8[i]);
		total = waddu8(total, a);
	}

	EXPECT_EQ(0, whaddu8(total));
}

UTEST_F(Zero, u16)
{
	ASSERT_EQ(length % WUINT16_WIDTH, 0);
	wuint16_t total = wsetu16(0);
	for (size_t i = 0; i < length; i += WUINT16_WIDTH) {
		wuint16_t a = wloadu16((wuint16_t*) &utest_fixture->u16[i]);
		total = waddu16(total, a);
	}

	EXPECT_EQ(0, whaddu16(total));
}

UTEST_F(Zero, u32)
{
	ASSERT_EQ(length % WUINT32_WIDTH, 0);
	wuint32_t total = wsetu32(0);
	for (size_t i = 0; i < length; i += WUINT32_WIDTH) {
		wuint32_t a = wloadu32((wuint32_t*) &utest_fixture->u32[i]);
		total = waddu32(total, a);
	}

	EXPECT_EQ(0, whaddu32(total));
}

UTEST_F(Zero, u64)
{
	ASSERT_EQ(length % WUINT64_WIDTH, 0);
	wuint64_t total = wsetu64(0);
	for (size_t i = 0; i < length; i += WUINT64_WIDTH) {
		wuint64_t a = wloadu64((wuint64_t*) &utest_fixture->u64[i]);
		total = waddu64(total, a);
	}

	EXPECT_EQ(0, whaddu64(total));
}



/** TODO
 * UTEST_F(Zero, i8)
 * UTEST_F(Zero, i16)
 * UTEST_F(Zero, i32)
 * UTEST_F(Zero, i64)
 * UTEST_F(Zero, f32)
 * UTEST_F(Zero, f64)
 */

UTEST_MAIN();
