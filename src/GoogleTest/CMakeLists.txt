# cmake 
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)

set(gtest_force_shared_crt ON CACHE BOOL "Force google test to link C runtimes dynamically" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
    hello_test
    hello_test.cpp
)

target_link_libraries(
    hello_test
    GTest::gtest_main
)

# cmake integrated module for GoogleTest
# provide 2 mechanisms for adding/finding tests within test binaries which has their advantages and drawbacks
# gtest_discover_tests
# gtest_add_tests
include(GoogleTest)
gtest_discover_tests(hello_test)