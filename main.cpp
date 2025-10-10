#include <iostream>
#include "class_BitString.h"

int main() {
    BitString a("10101");
    BitString b("00111");
    std::cout << "10101 AND 00111 = " << a.And(b).ToString() << std::endl;
    std::cout << "10101 OR 00111 = " << a.Or(b).ToString() << std::endl;
    std::cout << "10101 XOR 00111 = " << a.Xor(b).ToString() << std::endl;
    std::cout << "NOT 10101 = " << a.Not().ToString() << std::endl;
    return 0;
}