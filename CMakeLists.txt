cmake_minimum_required(VERSION 3.29)
project(Student-Grade-Management)

include(CTest)

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

add_executable(SerializerTests
        tests/SerializerTests.cpp
        tests/SerializerTests.hpp
        Serializer.cpp
        Serializer.hpp)
add_test(SerializerTestDouble0 SerializerTests testDouble0)
add_test(SerializerTestDouble1 SerializerTests testDouble1)
add_test(SerializerTestString0 SerializerTests testString0)
add_test(SerializerTestCompound0 SerializerTests testCompound0)