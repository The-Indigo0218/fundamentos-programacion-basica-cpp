cmake_minimum_required(VERSION 4.0)
project(fundamentos_programacion_basica_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Modulo0_Fundamentos)

add_executable(fundamentos_programacion_basica_cpp
        Modulo0_Fundamentos/main_structs.cpp
        Modulo1_Texto/main_textos.cpp
        Modulo1_Texto/filtro_csv.cpp
        Modulo2_Binarios/main_binarios.cpp)
