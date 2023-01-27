cmake_minimum_required(VERSION 3.24.0)
project(
    tbb-cc-jobs
    VERSION 0.1.0
    LANGUAGES CXX)

set(target "ccjob")
set(CCJOB_TEST CMAKE_VS_WINDOWS_TARGET_PLATFORM_VERSION_MAXIMUM)

include(cmake/CompileOptions.cmake)
include(cmake/Dependencies.cmake)
include(cmake/SourceLists.cmake)
include(cmake/Tests.cmake)

add_executable(
    ${target}
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)
target_sources(
    ${target}
        PRIVATE
            ${CCJOB_SRC}
)
target_include_directories(
    ${target}
        PRIVATE
            ${CCJOB_INCLUDE_DIR}
)
target_link_libraries(
    ${target}
        PRIVATE
            ${CCJOB_LINK_LIBRARY}
)
target_compile_features(
    ${target}
        PRIVATE
            cxx_std_20
)
target_compile_options(
    ${target}
        PRIVATE
            ${CCJOB_COMPILE_OPTION}
)
set_target_properties(
    ${target}
        PROPERTIES
            ${CCJOB_PROPERTY}
)
