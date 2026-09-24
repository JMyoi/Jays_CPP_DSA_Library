// Tiny main() used to build one test bench on its own (e.g. `make test_array_list`).
// The Makefile compiles this file once per test, passing the test function's name
// in with -DTEST_FN=ArrayListTest, so the same file can run any single test bench.
#include "test_bench.h"

#ifndef TEST_FN
#error "Build this through the Makefile, which defines TEST_FN (e.g. -DTEST_FN=ArrayListTest)"
#endif

int main(){
    TEST_FN();
    return 0;
}
