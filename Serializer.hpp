#pragma once
#include "ADTs.hpp"
#include <vector>

class Serializer {
public:
    static constexpr int LATEST_VERSION = 1;

    Serializer();
    Serializer(int);
    ~Serializer();

    int getVersion() const;

    std::vector<std::byte> serialize(const Student &) const;
    Student deserialize(const std::vector<std::byte> &) const;

private:
    const int version;

    // serializing functions
    static void serialize(const Student &, std::vector<std::byte> &);
    static void serialize(const Assignment &, std::vector<std::byte> &);
    static void serialize(const std::string &, std::vector<std::byte> &);
    static void serialize(const double &, std::vector<std::byte> &);

    // deserializing functions
    static Student deserialize_student(const std::vector<std::byte> &, std::size_t &);
    static Assignment deserialize_assignment(const std::vector<std::byte> &, std::size_t &);
    static std::string deserialize_string(const std::vector<std::byte> &, std::size_t &);
    static double deserialize_double(const std::vector<std::byte> &, std::size_t &);

    friend class SerializerTests;
};

