cmake_minimum_required(VERSION 3.10)

#CORTE 3 ENTREGA 1
project(Entrega_Corte3_DSPS)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------------------------------------------
# COMPILACIÓN DE EJECUTABLES
# -------------------------------------------------------------------

# 1. ATM
add_executable(ejercicio_atm 
    ATM/ATM.cpp 
    ATM/ATM.h 
    ATM/main.cpp
)

# 2. AuctionSystem
add_executable(ejercicio_auction 
    AuctionSystem/AuctionSystem.cpp 
    AuctionSystem/AuctionSystem.h 
    AuctionSystem/main.cpp
)

# 3. Clock
add_executable(ejercicio_clock 
    Clock/Clock.cpp 
    Clock/Clock.h 
    Clock/main.cpp
)

# 4. Meetup
add_executable(ejercicio_meetup 
    Meetup/Meetup.cpp 
    Meetup/Meetup.h 
    Meetup/Main.cpp
)

# 5. UndergroundSystem
add_executable(ejercicio_underground 
    UndergroundSystem/UndergroundSystem.cpp 
    UndergroundSystem/UndergroundSystem.h 
    UndergroundSystem/main.cpp
)