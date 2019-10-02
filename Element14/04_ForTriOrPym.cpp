// pay attention to:
// * the function times
// * practice of for loop
// * the use of i, j and k

#include <iostream>
using namespace std;

int times()
{
	int num = 0;
	cout << "how many levels would you like to create? ";
	cin >> num;
	return num;
}

int main() {
	string choose = "";
	cout << "create triangle or pyramid? ";
	cin >> choose;
	
	if (choose == "triangle") {
		int num = times();
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < (i+1); j++) {
				cout << "*";
			}
			cout << endl;
		}
	} else if (choose == "pyramid") {
		int num = times();
		for (int i = 0; i < num; i++) {
			for (int j = 0; j < (num-i-1); j++) {
				cout << " ";
			}
			for (int k = 0; k < (i*2+1); k++) {
				cout << "*";
			}
			cout << endl;
		}
		
	} else {
		cout << "sorry, we cannot support your choose." << endl;
	}
	
	return 0;
}
