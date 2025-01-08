cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Enable testing
enable_testing()

# Include gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add executable
add_executable(test_runner main.cpp test.cpp)

# Link gtest and pthread
target_link_libraries(test_runner ${GTEST_LIBRARIES} pthread)
