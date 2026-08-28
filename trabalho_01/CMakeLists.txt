cmake_minimum_required(VERSION 3.31.6)
project(trabalho_01 C)

set(CMAKE_C_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(trabalho_01 
    main.c 
    src/questoes/q54.c
    src/questoes/q125.c
    src/questoes/q163.c
    src/questoes/q181.c
    src/questoes/q240.c
    src/questoes/q243.c

)

target_link_libraries(trabalho_01 m)