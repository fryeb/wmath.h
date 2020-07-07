project('wmath.h', ['c', 'cpp'])

includes = include_directories('test/vendor')

# Check the library compiles as C and C++
test_c = library('test_c', 'test/test.c')
test_cpp = library('test_cpp', 'test/test.cpp')

test('utest', executable('utest', 'test/utest.c', include_directories: includes))
