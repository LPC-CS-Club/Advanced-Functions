//
// Created by light on 11/17/2024.
//

#include "SerializerTests.hpp"
#include <array>
#include <cmath>

int main(int argc, char* argv[]) {
    const auto tests = SerializerTests();

    if (argc < 2) {
        return 1;
    }

    if (argv[1] == "testDouble0"s) {
        return tests.testDouble0();
    }
    if (argv[1] == "testDouble1"s) {
        return tests.testDouble1();
    }
    std::cout << "Test " << argv[1] << " not found!" << std::endl;

    return 1;
}


SerializerTests::SerializerTests() : serializer() {}

SerializerTests::SerializerTests(const int version) : serializer(version) {}

int SerializerTests::testDouble0() const {
    std::vector<std::byte> data;

    constexpr int SIZE = 10;

    std::array<double, SIZE> doubles = {2.3, 3.14, -17, 3e8, 6.02e23, 1.6e-19, 0, -0, INFINITY, -INFINITY};
    for (double value : doubles) {
        serializer.serialize(value, data);
    }

    std::array<double, SIZE> outputDoubles{};
    std::size_t index = 0;
    for (int i = 0; i < SIZE; i++) {
        outputDoubles[i] = serializer.deserialize_double(data, index);
    }

    if (doubles != outputDoubles) {
        std::cout << "Expected:";
        for (std::size_t i = 0; i < SIZE; i++) {
            std::cout << " " << doubles[i];
        }
        std::cout << std::endl;
        std::cout << "Result:";
        for (std::size_t i = 0; i < SIZE; i++) {
            std::cout << " " << outputDoubles[i];
        }
        std::cout << std::endl;
        return 1;
    }

    if (index != sizeof(double) * SIZE) {
        return 1;
    }
    return 0;
}

int SerializerTests::testDouble1() const {
    std::vector<std::byte> data;
    std::vector<double> values;

    for (int x = -100; x <= 100; x++) {
        values.push_back(-3.4 * x * x + 17.0 * x + 41.23);
    }

    for (double value: values) {
        serializer.serialize(value, data);
    }

    std::size_t index = 0;
    std::vector<double> outputDoubles;
    for (int i = 0; i < values.size(); i++) {
        outputDoubles.push_back(serializer.deserialize_double(data, index));
    }

    return values == outputDoubles && index == sizeof(double) * values.size() ? 0 : 1;
}
