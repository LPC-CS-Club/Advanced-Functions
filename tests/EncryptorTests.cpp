#include "EncryptorTests.hpp"

#include <cassert>
#include <iostream>
#include <limits>
using namespace std::string_literals;

int main(const int argc, char* argv[]) {
    const auto encryptorTests = EncryptorTests();

    if (argc < 2) return 1;

    if (argv[1] == "testEncryption0"s) {
        return encryptorTests.testEncryption0();
    }
    std::cout << "Test " << argv[1] << " not found!\n";

    return 1;
}

EncryptorTests::EncryptorTests() : encryptor() {}

EncryptorTests::EncryptorTests(const int version) : encryptor(version) {}

EncryptorTests::~EncryptorTests() = default;

int EncryptorTests::testEncryption0() const {
    constexpr auto size = std::to_integer<int>(std::numeric_limits<std::byte>::max());
    std::vector<std::byte> data(size);
    for (int i = 0; i < size; i++) {
        data.at(i) = std::byte{i};
    }

    auto copy = std::vector<std::byte>(data);
    const std::string password = "Password123!";

    encryptor.encrypt(copy, password);
    assert(data != copy);
    encryptor.decrypt(copy, password);
    assert(data == copy);

    return 0;
}
