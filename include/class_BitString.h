#ifndef CLASS_BITSTRING_H
#define CLASS_BITSTRING_H

#include <string>
#include <stdexcept>

class BitString {
public:
    BitString() = default;
    BitString(const size_t& n, unsigned char t = 0);
    BitString(const unsigned char* arr, size_t n);
    BitString(const std::string& s);
    virtual ~BitString() noexcept;

    BitString And(const BitString& other) const;
    BitString Or(const BitString& other) const;
    BitString Xor(const BitString& other) const;
    BitString Not() const;

    std::string ToString() const;

private:
    unsigned char* data;
    size_t length;
};

#endif
