cmake_minimum_required(VERSION 3.21)
project(imitationAudioPlayer_26_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(imitationAudioPlayer_26_1 main.cpp include/classes.h)

target_include_directories(imitationAudioPlayer_26_1 PUBLIC include)