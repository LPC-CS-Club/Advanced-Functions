#pragma once
#include "Encryptor.hpp"

class EncryptorTests {
private:
    Encryptor encryptor;
public:
    EncryptorTests();
    EncryptorTests(int);
    ~EncryptorTests();

    int testEncryption0() const;
};

