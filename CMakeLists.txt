cmake_minimum_required(VERSION 3.15)

project(pong CXX)

include(cmake/Cache.cmake)
include(cmake/StandardProjectSettings.cmake)
include(cmake/PreventInSourceBuilds.cmake)

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

add_library(project_warnings INTERFACE)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

include(cmake/Doxygen.cmake)
enable_doxygen()

include(cmake/StaticAnalyzers.cmake)

find_package(sgg REQUIRED)

add_library(${PROJECT_NAME}
    src/test.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC 
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC 
        project_options 
        project_warnings 
        sgg::sgg
)

add_executable(${PROJECT_NAME}_exe 
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}_exe PRIVATE ${PROJECT_NAME})

option(ENABLE_TESTING "Allow tests to be built" ON)

if (ENABLE_TESTING)
    add_subdirectory(test)
endif()
