#include "SerializerTests.hpp"
#include <array>
#include <cassert>
#include <cmath>

int main(const int argc, char* argv[]) {
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
    if (argv[1] == "testString0"s) {
        return tests.testString0();
    }
    if (argv[1] == "testCompound0"s) {
        return tests.testCompound0();
    }
    std::cout << "Test " << argv[1] << " not found!" << std::endl;

    return 1;
}


SerializerTests::SerializerTests() : serializer() {}

SerializerTests::SerializerTests(const int version) : serializer(version) {}

int SerializerTests::testDouble0() const {
    std::vector<std::byte> data;

    constexpr int SIZE = 13;

    std::array<double, SIZE> doubles = {2.3, 3.14, -17, 3e8, 6.02e23, 1.6e-19, 0, -0, INFINITY,
        static_cast<double>(-INFINITY), NAN, std::nan("1"), std::nan("259")};
    for (double value : doubles) {
        Serializer::serialize(value, data);
    }

    std::array<double, SIZE> outputDoubles{};
    std::size_t index = 0;
    for (int i = 0; i < SIZE; i++) {
        outputDoubles[i] = Serializer::deserialize_double(data, index);
    }

    for (int i = 0; i < SIZE; i++) {
        if (doubles[i] == outputDoubles[i]) {
            continue;
        }

        // NaN for some reason is not equal to itself
        // check for this and compare these two in a special case
        if (isnan(doubles[i]) && isnan(outputDoubles[i])) {
            // do a byte comparison
            auto ptr1 = reinterpret_cast<std::byte*>(&doubles[i]);
            auto ptr2 = reinterpret_cast<std::byte*>(&outputDoubles[i]);
            bool equal_flag = true;
            for (int j = 0; j < sizeof(double); j++) {
                if (ptr1[j] != ptr2[j]) {
                    equal_flag = false;
                    break;
                }
            }
            if (equal_flag) continue;
        }

        std::cout << doubles[i] << " != " << outputDoubles[i] << std::endl;
        return 1;
    }

    return index == sizeof(double) * SIZE ? 0 : 1;
}

int SerializerTests::testDouble1() const {
    std::vector<std::byte> data;
    std::vector<double> values;

    for (int x = -100; x <= 100; x++) {
        values.push_back(-3.4 * x * x + 17.0 * x + 41.23);
    }

    for (double value: values) {
        Serializer::serialize(value, data);
    }

    std::size_t index = 0;
    std::vector<double> outputDoubles;
    for (int i = 0; i < values.size(); i++) {
        outputDoubles.push_back(Serializer::deserialize_double(data, index));
    }

    return values == outputDoubles && index == sizeof(double) * values.size() ? 0 : 1;
}

int SerializerTests::testString0() const {
    std::vector<std::byte> data;
    std::vector<std::string> msgs = {
        "Hello World!",
        "Let's hope all the tests pass!",
        "",
        "\a\b\f\n\r\t\v\\\'\""
        "Goodbye!"
    };
    for (const std::string& msg : msgs) {
        Serializer::serialize(msg, data);
    }
    std::vector<std::string> outputStrings;
    std::size_t index = 0;
    for (int i = 0; i < msgs.size(); i++) {
        outputStrings.push_back(Serializer::deserialize_string(data, index));
    }

    if (msgs.size() != outputStrings.size()) {
        std::cout << "Expected " << msgs.size() << " strings but got " << outputStrings.size() << " instead!"
            << std::endl;
        return 1;
    }

    for (int i = 0; i < msgs.size(); i++) {
        if (msgs[i] != outputStrings[i]) {
            std::cout << "Expected " << msgs[i] << " but got " << outputStrings[i] << std::endl;
            return 1;
        }
    }

    return index == data.size() * sizeof(char) ? 0 : 1;
}

int SerializerTests::testCompound0() const {
    double a = 234.54;
    double b = -12.43094;
    std::string c = "This isn't a double";
    double d = -9.81;
    std::string e = "3.141592653589793";
    double f = 0.0;

    std::vector<std::byte> data;
    Serializer::serialize(a, data);
    Serializer::serialize(b, data);
    Serializer::serialize(c, data);
    Serializer::serialize(d, data);
    Serializer::serialize(e, data);
    Serializer::serialize(f, data);

    std::size_t index = 0;
    assert(Serializer::deserialize_double(data, index) == a);
    assert(Serializer::deserialize_double(data, index) == b);
    assert(Serializer::deserialize_string(data, index) == c);
    assert(Serializer::deserialize_double(data, index) == d);
    assert(Serializer::deserialize_string(data, index) == e);
    assert(Serializer::deserialize_double(data, index) == f);

    assert(index == data.size());
    return 0;
}
