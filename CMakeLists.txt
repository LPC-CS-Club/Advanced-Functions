cmake_minimum_required(VERSION 3.29)
project(Student-Grade-Management)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(Student-Grade-Management
    addGrades.cpp
    addGrades.hpp
    advancedFunctions.cpp
    advancedFunctions.hpp
    input.cpp
    input.hpp
    main.cpp
    removeGrades.cpp
    removeGrades.hpp
    search.cpp
    search.hpp
    viewGrades.cpp
    viewGrades.hpp
        Serializer.cpp
        Serializer.hpp)
