project('wmath.h', ['c', 'cpp'])

includes = include_directories('test/vendor')
cc = meson.get_compiler('c')
libm = cc.find_library('libm', required: false)

# Check the library compiles as C and C++
test_c = library('test_c', 'test/test.c')
test_cpp = library('test_cpp', 'test/test.cpp')

tests = [
	'zero',
	'sum'
]

foreach test_name : tests
	src = 'test/' + test_name + '.c'

	# Scalar test
	test (
		test_name + '_scalar',
		executable(
			'test_' + test_name + '_scalar',
			src,
			include_directories: includes,
			c_args: '-DWMATH_FORCE_SCALAR',
			dependencies: libm))

	# TODO: SIMD test
endforeach
