#include <iostream>
using namespace std;

void DemoConsoleOutput();

int main() {
    DemoConsoleOutput();
    return 0;
}

void DemoConsoleOutput() {
    cout << "This is a simple string literal" << endl;
    cout << "Pi is close to: " << 22 / 7 << endl;
    cout << "Pi is more close to: " << 22.0 / 7 << endl;
}