cmake_minimum_required(VERSION 3.10)

enable_language(CXX)

add_executable(tests
    src/tests.cpp
)

find_package(GTest CONFIG REQUIRED)
find_package(rapidcheck CONFIG REQUIRED)
find_package(Threads REQUIRED)

target_include_directories(tests
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_link_libraries(tests
    PRIVATE
        ${CMAKE_PROJECT_NAME}
        Threads::Threads
        GTest::gtest
        GTest::gmock
        rapidcheck
        rapidcheck_gtest
        rapidcheck_gmock
)

add_custom_target(run_tests
    COMMAND ${CMAKE_COMMAND} -E env RC_PARAMS='max_size=100 max_success=1000' $<TARGET_FILE:tests>
    DEPENDS tests
)
