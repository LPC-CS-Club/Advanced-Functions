#include "Encryptor.hpp"

#include <stdexcept>

Encryptor::Encryptor() : Encryptor(LATEST_VERSION) {}

Encryptor::Encryptor(const int version) : version(version) {}

Encryptor::~Encryptor() = default;

int Encryptor::getVersion() const {
    return version;
}


void Encryptor::encrypt(std::vector<std::byte> &data, const std::string &password) const {
    throw std::runtime_error("Encryptor::encrypt is not implemented");
}

void Encryptor::decrypt(std::vector<std::byte> &data, const std::string &password) const {
    throw std::runtime_error("Encryptor::decrypt is not implemented");
}
