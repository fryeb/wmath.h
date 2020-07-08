project('wmath.h', ['c', 'cpp'])

includes = include_directories('test/vendor')
cc = meson.get_compiler('c')
libm = cc.find_library('libm', required: false)

if cc.get_argument_syntax() == 'gcc'
	avx_args = '-mavx2'
else
	avx_args = ''
endif

# Check the library compiles as C and C++
test_c = library('test_c', 'test/test.c', c_args: avx_args)
test_cpp = library('test_cpp', 'test/test.cpp', cpp_args: avx_args)
test_c_scalar = library('test_c_scalar', 'test/test.c', c_args: '-DWMATH_FORCE_SCALAR')
test_cpp_scalar = library('test_cpp_scalar', 'test/test.cpp', cpp_args: '-DWMATH_FORCE_SCALAR')

tests = [
	'zero',
	'sum'
]

foreach test_name : tests
	src = 'test/' + test_name + '.c'

	# Main test
	test (
		test_name,
		executable(
			'test_' + test_name,
			src,
			include_directories: includes,
			c_args: avx_args,
			dependencies: libm))

	# Scalar test
	test (
		test_name + '_scalar',
		executable(
			'test_' + test_name + '_scalar',
			src,
			include_directories: includes,
			c_args: '-DWMATH_FORCE_SCALAR',
			dependencies: libm))
endforeach
