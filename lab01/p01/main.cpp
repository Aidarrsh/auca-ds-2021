#include <iostream>

int main() {
#ifdef AUCA_DEBUG
    std::cout << "Author: Aidar Sharipov\n";
#endif
    std::cout << "Hello, C++" << __cplusplus << "!!!\n";
}