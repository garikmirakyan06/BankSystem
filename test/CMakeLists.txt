cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(external/googletest)

add_executable(Test test.cc ${SOURCE_FILES})

target_include_directories(Test PUBLIC ../include ../include/Screens)
target_link_libraries(Test PRIVATE gtest gtest_main nlohmann_json::nlohmann_json)

