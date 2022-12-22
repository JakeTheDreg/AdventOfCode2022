cmake_minimum_required(VERSION 3.23)
project(Day5Part1 C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS "-Wall -fstack-protector -Wextra -Wfloat-equal -Wcast-align")

add_executable(Day5Part1 main.c)