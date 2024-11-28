#pragma once
#include <string>
#include <vector>

class Encryptor {
public:
    static constexpr int LATEST_VERSION = 1;

    Encryptor();
    Encryptor(int);
    ~Encryptor();

    int getVersion() const;

    void encrypt(std::vector<std::byte>&, const std::string&) const;
    void decrypt(std::vector<std::byte>&, const std::string&) const;

private:
    const int version;

};
