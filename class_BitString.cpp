#include "class_BitString.h"

BitString::BitString() : data(nullptr), length(0) {}

BitString::BitString(const size_t& n, unsigned char t): data(nullptr), length(n) {
    if (n == 0)
        return;
    if (t != 0 && t != 1)
        throw std::invalid_argument("Бит может быть только 0 или 1");
    data = new unsigned char[n];
    std::fill(data, data + n, t);
}

BitString::BitString(const std::initializer_list<unsigned char>& t): data(nullptr), length(t.size()) {
    data = new unsigned char[length];
    size_t i = 0;
    for (auto bit : t) {
        if (bit != 0 && bit != 1)
            throw std::invalid_argument("Бит может быть только 0 или 1");
        data[i++] = bit;
    }
}

BitString::BitString(const std::string& s): data(nullptr), length(s.size()) {
    data = new unsigned char[length];
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '0')
            data[i] = 0;
        else if (s[i] == '1')
            data[i] = 1;
        else
            throw std::invalid_argument("Недопустимый символ в строке");
    }
}

BitString::BitString(const BitString& other) : data(nullptr), length(other.length) {
    if (length == 0) {
        data = nullptr;
        return;
    }
    data = new unsigned char[length];
    std::copy(other.data, other.data + length, data);
}

BitString::BitString(BitString&& other) noexcept: data(other.data), length(other.length) {
    other.data = nullptr;
    other.length = 0;
}

BitString::~BitString() noexcept {
    delete[] data;
}

BitString BitString::And(const BitString& other) const {
    if (length != other.length)
        throw std::invalid_argument("Длины битовых строк не совпадают");
    BitString result(length);
    for (size_t i = 0; i < length; ++i)
        result.data[i] = data[i] & other.data[i];
    return result;
}

BitString BitString::Or(const BitString& other) const {
    if (length != other.length)
        throw std::invalid_argument("Длины битовых строк не совпадают");
    BitString result(length);
    for (size_t i = 0; i < length; ++i)
        result.data[i] = data[i] | other.data[i];
    return result;
}

BitString BitString::Xor(const BitString& other) const {
    if (length != other.length)
        throw std::invalid_argument("Длины битовых строк не совпадают");
    BitString result(length);
    for (size_t i = 0; i < length; ++i)
        result.data[i] = data[i] ^ other.data[i];
    return result;
}

BitString BitString::Not() const {
    BitString result(length);
    for (size_t i = 0; i < length; ++i) {
        if (data[i] == 0)
            result.data[i] = 1;
        else
            result.data[i] = 0;
    }
    return result;
}

std::string BitString::ToString() const {
    std::string res;
    res.reserve(length);
    for (size_t i = 0; i < length; ++i) {
        if (data[i] == 0)
            res += '0';
        else
            res += '1';
    }
    return res;
}