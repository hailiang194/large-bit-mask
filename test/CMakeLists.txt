set(BUILD_SHARED_LIBS OFF)
target_compile_definitions(large_bit_mask PUBLIC RUN_TEST)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
  large_bit_mask_test
  src/capacity_size.cpp
  src/init_bit_mask.cpp
  src/set_bit.cpp
)
target_link_libraries(
    large_bit_mask_test
    large_bit_mask
    GTest::gtest_main
)

add_test(NAME Test COMMAND large_bit_mask_test --gtest_output=xml:${CMAKE_CURRENT_BINARY_DIR}/TestResult/XML_Report.xml)

include(GoogleTest)
gtest_discover_tests(large_bit_mask_test)
