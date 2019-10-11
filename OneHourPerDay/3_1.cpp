#include <iostream>
using namespace std;

int main() {
    cout << "multiply two numbers" << endl;
    cout << "first number: ";
    int firstnum = 0;
    cin >> firstnum;
    cout << "second number: ";
    int secondnum = 0;
    cin >> secondnum;
    int res = firstnum * secondnum;
    cout << firstnum << " * " << secondnum;
    cout << " = " << res << endl;
    return 0;
}