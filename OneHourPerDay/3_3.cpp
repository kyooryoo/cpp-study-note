#include <iostream>
using namespace std;

int main() {
    unsigned short uShort = 65535;
    cout << "Incrementing unsigned short " << uShort << " gives: ";
    cout << ++uShort << endl;

    short sShort = 32767;
    cout << "Incrementing signed short " << sShort << " gives: ";
    cout << ++sShort << endl;

    return 0;
}