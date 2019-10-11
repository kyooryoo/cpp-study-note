#include <iostream>
#include <string>
using namespace std;

int main() {
    int age;
    string name;

    cout << "your name: ";
    cin >> name;
    cout << "your age:" ;
    cin >> age; 
    cout << name << " is " << age << " years old." << endl;
    return 0;
}