// pay attention to:
// * recall that define pointer: *ptr = &var
// * `*` operator returns the value of a pointer pointing to
// * `&` operator returns the address of a variable
// * const applies on the pointer or the pointed variable

#include <iostream>
using namespace std;

// passed in arg could be a constant or not
// but a const arg could not be changed within the func
int func(const double& value) {
	// assignment of read-only reference `value`
	//value = 333;
	return value;
}

class MyClass {
	private:
		int _value;
	public:
		// `const` after a func definition within a class means:
		// the func will not change any variable in the class
		void NoChanges() const {
			//value = 1; // assignment of member in ready-only object
		}
};

int main() {
	double E = 2.71828;
	
	// constant value
	const double PI = 3.14;
	cout << "the value of PI: " << PI << endl;
	//PI = 5; // Compiler Error
	const double data[] = {1.0, 2.0, 3.0};
	cout << "the value of data[2]: " << data[2] << endl;
	//data[2] = 5.0; // Compiler Error

	// the `const` before the pinter type defines what it points to

	// pointer points to a constant
	const double* ptr1 = &PI; // what *ptr points to is a constant
	cout << "the value of *ptr1 is: " << *ptr1 << endl;
	// cannot modify the constant through the pointer
	//*ptr = 5.0; // Compiler Error
	
	// pointer points to a non-constant
	ptr1 = &E; // the pointer could be modified to point to others
	cout << "after update *ptr1 its value is: " << *ptr1 << endl;
	E = 2.72; // can change the value of E through the E var
	// cannot change the value of E through the pointer
	//ptr1 = 2.71828 // cannot convert `double` to `const double`
	cout << "update the var that *ptr1 points to: " << *ptr1 << endl;

	// the `const` before a pointer defines the pointer itself

	// constant pointer
	const double* const ptr2 = &PI; // the *ptr itself is a constant
	cout << "the value of *ptr2 is: " << *ptr2 << endl;
	//ptr2 = &E; // assignment of read-only variable `ptr2`
	
	// enforcing const
	// invalid conversion from `const double*` to `double*`
	//double* ptr3 = &PI;
	// as PI is a constant, the `const` before *ptr3 is mandatory
	const double* ptr3 = &PI;
	// constant pointer can point to a var as well
	ptr3 = &E;
	cout << "the value of *ptr3 before udpate E: " << *ptr3 << endl;
	// while you can change the value of var through the var
	E = 2.71828;
	cout << "the value of *ptr3 after udpate E: " << *ptr3 << endl;
	// you cannot change the value of var through its constant pointer
	//*ptr3 = 2.71828 // assignment of read-only location `*ptr3`
	
	cout << "passed in arg for func could be a constant: " 
		<< func(PI) << endl;
	cout << "or could be a non-constant as well: " << func(E) << endl;
		
	return 0;
}
