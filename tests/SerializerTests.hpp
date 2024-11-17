#pragma once

#include "Serializer.hpp"

class SerializerTests {
private:
    Serializer serializer;
public:
    SerializerTests();
    SerializerTests(int);

    int testDouble0() const;
    int testDouble1() const;
    int testString0() const;
    int testCompound0() const;
};
