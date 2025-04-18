cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
project(student LANGUAGES CXX)

set(GTEST_DIR $ENV{HOME}/googletest)
include_directories(${GTEST_DIR}/googletest/include)


# Add your source files
add_executable(${PROJECT_NAME} 
        src/shape.cpp
        test/test.cpp
)

# Link Google Test libraries
target_link_libraries(${PROJECT_NAME} 
        ${GTEST_DIR}/build/lib/libgtest.a
        ${GTEST_DIR}/build/lib/libgtest_main.a
)