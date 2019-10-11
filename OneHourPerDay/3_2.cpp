#include <iostream>
using namespace std;

int MultiplyNumbers() {
    int firstNum = 0, secondNum = 0;
    cout << "multiply two numbers" << endl;
    cout << "first number: ";
    cin >> firstNum;
    cout << "second number: ";
    cin >> secondNum;
    return firstNum * secondNum;
}

void DisplayResult(int res) {
    cout << "the result is: " << res << endl;
}

int main() {
    int res = 0;
    res = MultiplyNumbers();
    DisplayResult(res);
    return 0;
}