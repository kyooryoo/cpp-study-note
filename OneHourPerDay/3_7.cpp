#include <iostream>
using namespace std;

constexpr double GetPi() { return 22.0/7; }
constexpr double TwicePi() { return 2 * GetPi();}

enum CardinalDirections {
    North = 25,
    South,
    East,
    West
};

int main() {
    cout << "THis is a constant as well." << endl;

    int decNum = 10;
    int octNum = 012;
    int binNum = 0b1010;

    cout << "Decimal 10: " << decNum << endl;
    cout << "Octal 012: " << octNum << endl;
    cout << "Binary 1010: " << binNum << endl;

    const double pi = 22.0 / 7;
    cout << "constant pi contains value " << pi << endl;
    cout << "constexpr GetPi() returns value " << GetPi() << endl;
    cout << "constexpr TwicePi() returns value " << TwicePi() << endl;

    cout << "Displaying directions and their symbolic values" << endl;
    cout << "North: " << North << endl;
    cout << "South: " << South << endl;
    cout << "East:" << East << endl;
    cout << "West: " << West << endl;
    CardinalDirections windDirection = South;
    cout << "Variable withDirection = " << windDirection << endl;
    
    return 0;
}