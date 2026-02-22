cmake_minimum_required(VERSION 3.20)
project(day1_algo_low_latency LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(algorithm_lab src/algorithm_lab_day1.cpp)
add_executable(latency_lab src/latency_lab_day1.cpp)

