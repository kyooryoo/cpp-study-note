// pay attention to:
// * the incorrect update1
// * the confusing update2
// * the correct update3

#include <iostream>
using namespace std;

void update1(int num) {
	num = 7;
	cout << "in update1, num is " << num << " at " << &num << endl;
}

void update2(int *ptr) {
	*ptr = 7;
	cout << "in update2, num is " << *ptr << " at " << ptr << endl;
}

void update3(int &num) {
	num = 7;
	cout << "in update3, num is " << num << " at " << &num << endl;
}

int main() {
	
	int num = 0; 
	
	num = 5;
	// test the func update1
	cout << "num in main is " << num << " at " << &num << endl;
	update1(num);
	cout << "after update1, num in main is " << num
		<< " at " << &num << endl;
	
	num = 5;
	// test the func update2
	cout << "num in main is " << num << " at " << &num << endl;
	int *ptr = &num;
	update2(ptr);
	cout << "after update2, num in main is " << num
		<< " at " << &num << endl;
	
	num = 5;
	// test the func update3
	cout << "num in main is " << num << " at " << &num << endl;
	update3(num);
	cout << "after update3, num in main is " << num
		<< " at " << &num << endl;

	return 0;
}
