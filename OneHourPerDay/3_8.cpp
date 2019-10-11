#include <iostream>

enum YourCards {Ace = 43, Jack, Queen, King};

int main() {
    using namespace std;

    cout << "the value of queen can be " << Queen << endl;

    unsigned int uInt = 0;
    int aInt = 0;
    bool res = sizeof(uInt) == sizeof(aInt);
    cout << "len of unsigned int equals to an int: " << res << endl;

    const auto pi = 22.0 / 7;
    cout << "input the redius of the circle: ";
    double radius = 0;
    cin >> radius;
    cout << "area of the circle is " << pi*radius*radius << endl;
    cout << "circumference of the circle is " << 2*pi*radius << endl;

    // for avoiding following error, initialize with `var{value}`
    int iArea = pi*radius*radius;
    int iCirc = 2*pi*radius;
    cout << "area of the circle in int is " << iArea << endl;
    cout << "circ of the circle in int is " << iCirc << endl;

    // uncomment to see the following bug
    // answer: needs initialization
    // answer: Integer is not a good var name
    // auto Integer;

    return 0;
}