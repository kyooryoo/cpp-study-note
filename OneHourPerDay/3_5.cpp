#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    cout << "Computing the size of C++11 fixed-width integer types:" << endl;

    cout << "Size of int8_t: " << sizeof(int8_t) << endl;
    cout << "Size of uint8_t: " << sizeof(uint8_t) << endl;
    cout << "Size of int16_t: " << sizeof(int16_t) << endl;
    cout << "Size of uint16_t: " << sizeof(uint16_t) << endl;
    cout << "Size of int32_t: " << sizeof(int32_t) << endl;
    cout << "Size of uint32_t: " << sizeof(uint32_t) << endl;
    cout << "Size of int64_t: " << sizeof(int64_t) << endl;
    cout << "Size of uint64_t: " << sizeof(uint64_t) << endl;
    return 0;
}