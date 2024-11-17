#pragma once
#include "ADTs.hpp"
#include <vector>

constexpr int LATEST_VERSION = 1;

class Serializer {
private:
    const int version;

    // serializing functions
    void serialize(const Student &, std::vector<std::byte> &) const;
    void serialize(const Assignment &, std::vector<std::byte> &) const;
    void serialize(const std::string &, std::vector<std::byte> &) const;
    void serialize(const double &, std::vector<std::byte> &) const;

    // deserializing functions
    Student deserialize_student(const std::vector<std::byte> &, std::size_t &) const;
    Assignment deserialize_assignment(const std::vector<std::byte> &, std::size_t &) const;
    std::string deserialize_string(const std::vector<std::byte> &, std::size_t &) const;
    double deserialize_double(const std::vector<std::byte> &, std::size_t &) const;

public:
    Serializer();
    Serializer(int);
    ~Serializer();

    int getVersion() const;

    std::vector<std::byte> serialize(const Student &) const;
    Student deserialize(const std::vector<std::byte> &) const;

    friend class SerializerTests;
};

