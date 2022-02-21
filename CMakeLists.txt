cmake_minimum_required(VERSION 3.20)
project(KDZ_ALGO)

set(CMAKE_CXX_STANDARD 14)

file(GLOB FILES "saver.h" "generators.h" "sorts/*.h" "main.cpp" "calculations/calculations.h")

add_executable(KDZ_ALGO ${FILES} generator_wrappers.h sorts/sorts.h definitions.h)