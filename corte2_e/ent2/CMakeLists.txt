cmake_minimum_required(VERSION 3.10)
project(ActividadEntregable2)

# Se debe ponet C++17 para que soporte todas las funciones modernas
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Crear 4 programas distintos
add_executable(ejecutable_twitter twitter.cpp)
add_executable(ejecutable_spreadsheet spreadsheet.cpp)
add_executable(ejecutable_robot robot_simulator.cpp)
add_executable(ejecutable_queens queen_attack.cpp)