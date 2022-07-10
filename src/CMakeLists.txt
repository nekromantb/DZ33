cmake_minimum_required(VERSION 3.22)

add_executable(DZ33 main.cpp task1.cpp task2.cpp task3.cpp task4.cpp)

target_include_directories(DZ33 PUBLIC ${CMAKE_SOURCE_DIR}/include)