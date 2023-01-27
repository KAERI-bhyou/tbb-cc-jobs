if(CCJOB_TEST)
enable_testing()
include(GoogleTest)

set(test_target "test_app")
add_executable(${test_target} test/test.cpp)
target_sources(
    ${test_target}
        PRIVATE
            ${CCJOB_SRC}
)
target_include_directories(
    ${test_target}
        PRIVATE
            ${CCJOB_INCLUDE_DIR}
)
target_link_libraries(
    ${test_target}
        PRIVATE
            ${CCJOB_LINK_LIBRARY}
            GTest::gtest_main
)
target_compile_features(
    ${test_target}
        PRIVATE
            cxx_std_20
)
target_compile_options(
    ${test_target}
        PRIVATE
            ${CCJOB_COMPILE_OPTION}
)
set_target_properties(
    ${test_target}
        PROPERTIES
            ${CCJOB_PROPERTY}
)

gtest_discover_tests(${test_target})
endif()
