cmake_minimum_required(VERSION 3.10)
project(Entrega_Valentina)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compilar los que ya funcionan
add_executable(manager ent3/manager.cpp)
add_executable(scores ent3/scores.cpp)
add_executable(crypto ent3/crypto.cpp)

# Configuración corregida para el banco
find_package(Threads REQUIRED)
add_executable(bank ent3/bank.cpp)
# Usamos la variable directa en lugar del alias
target_link_libraries(bank ${CMAKE_THREAD_LIBS_INIT})