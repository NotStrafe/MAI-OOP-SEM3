#pragma once

#include <initializer_list>
#include <string>
#include <stdexcept>


class BitString
{
public:
    BitString();
    BitString(const size_t &n, unsigned char t);
    BitString(const std::initializer_list<unsigned char> &t);
    BitString(const std::string &t);
    BitString(const BitString &other);
    BitString(BitString &&other) noexcept;
    ~BitString() noexcept;

    BitString &operator=(const BitString &other);
    BitString &operator&=(const BitString &other);
    BitString &operator|=(const BitString &other);
    BitString &operator^=(const BitString &other);
    BitString operator~() const;

    bool operator==(const BitString &other) const;
    bool operator<(const BitString &other) const;
    bool operator>(const BitString &other) const;

    size_t getSize() const;
    unsigned char *getData() const;

private:
    size_t _size;
    unsigned char *_data;

    void validateBit(unsigned char digit);
};