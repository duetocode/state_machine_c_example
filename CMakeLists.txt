cmake_minimum_required(VERSION 3.0.0)
project(finite_state_machine VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB C_SRC
    *.c
    **/*.c
)

add_executable(machine ${C_SRC})
target_include_directories(machine PRIVATE . state_machine)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
