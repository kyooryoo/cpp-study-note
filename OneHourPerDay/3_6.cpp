#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    auto coinFlippedHeads = true;
    auto largeNumber = 2500'000'000'000;

    cout << "coinFlippedHeads: value: " << coinFlippedHeads;
    cout << ", type: " << typeid(coinFlippedHeads).name();
    cout << ", size: " << sizeof(coinFlippedHeads) << endl;

    cout << "largeNumber: value: " << largeNumber;
    cout << ", type: " << typeid(largeNumber).name();
    cout << ", size: " << sizeof(largeNumber) << endl;

    typedef unsigned int STRICTLY_POSITIVE_INTEGER;
    STRICTLY_POSITIVE_INTEGER numEggInBusket = 4'321;

    cout << "numEggInBusket: value: " << numEggInBusket;
    cout << ", type: " << typeid(numEggInBusket).name();
    cout << ", size: " << sizeof(numEggInBusket) << endl;

    return 0;
}