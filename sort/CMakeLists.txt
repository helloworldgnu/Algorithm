cmake_minimum_required(VERSION 3.10.2)

project(Sort VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

aux_source_directory(. DIR_SRCS)

add_executable(Sort ${DIR_SRCS})