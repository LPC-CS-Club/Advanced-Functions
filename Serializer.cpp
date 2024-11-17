#include "Serializer.hpp"


Serializer::Serializer() : Serializer(LATEST_VERSION) {}

Serializer::Serializer(const int version) : version(version) {}

Serializer::~Serializer() = default;

int Serializer::getVersion() const {
    return version;
}

std::vector<std::byte> Serializer::serialize(const Student &student) const {
    std::vector<std::byte> data;
    serialize(student, data);
    return data;
}

Student Serializer::deserialize(const std::vector<std::byte> &data) const {
    std::size_t index = 0;
    return deserialize_student(data, index);
}


void Serializer::serialize(const std::string &str, std::vector<std::byte> &byte_array) const {
    const auto * bytes = reinterpret_cast<const std::byte *>(str.c_str());
    for (std::size_t i = 0; i <= str.length(); ++i) {
        byte_array.push_back(bytes[i]);
    }
}

void Serializer::serialize(const double &val, std::vector<std::byte> &byte_array) const {
    const auto *bytes = reinterpret_cast<const std::byte *>(&val);
    for (std::size_t i = 0; i < sizeof(double); i++) {
        byte_array.push_back(bytes[i]);
    }
}

std::string Serializer::deserialize_string(const std::vector<std::byte> &byte_array, std::size_t &index) const {
    const auto *charPtr = reinterpret_cast<const char *>(byte_array.data()+index);
    std::string str(charPtr);
    index += str.length() + 1;
    return str;
}

double Serializer::deserialize_double(const std::vector<std::byte> &byte_array, std::size_t &index) const {
    const auto val = *bit_cast<double *>(byte_array.data() + index);
    index += sizeof(double);
    return val;
}