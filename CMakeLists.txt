cmake_minimum_required(VERSION 3.15)

project(quadratic_equation C)

set(CMAKE_C_STANDARD 11)

add_compile_options( -Wall -Wextra -pedantic)

add_executable(quadratic_equation src/solver_quadratic_equation.c src/equation_lib.h src/equation_lib.c)

add_executable(
        tests
        tests/tests.c
        tests/test_lib.h
        src/equation_lib.c
        src/equation_lib.h)

add_executable(
        tests_from_file
        tests/tests_from_file.c
        src/equation_lib.c
        src/equation_lib.h
)

target_link_libraries(quadratic_equation PRIVATE m)
target_link_libraries(tests PRIVATE m)
target_link_libraries(tests_from_file  PRIVATE m)