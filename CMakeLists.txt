cmake_minimum_required(VERSION 4.2)
project(Inventory)

set(CMAKE_CXX_STANDARD 20)

add_executable(Inventory main.cpp
        food.h
        beverage.h
        inventory.h
        inventory.cpp
        log.h
        Utils.h
        audit.h
        Color.h
        Log.cpp
        Utils.cpp
        Audit.cpp)
