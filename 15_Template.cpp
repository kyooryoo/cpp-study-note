// template could be used for function and class
// with template, the input data type could be flexible
#include <iostream>
using namespace std;

template <class T>
T Add(T a, T b) {
	return a + b;
}

template <class T>
class Complex {
	public:
	T Real;
	T Imag;

	Complex(T real, T imag) {
		Real = real;
		Imag = imag;
	}
};

int main() {
	// function template accepts various types of args
	double d1 = 2.3;
	double d2 = 3.4;
	cout << "adding 2.3 and 3.4 gets: " << Add(d1, d2) << endl;
	int i1 = 4;
	int i2 = 5;
	cout << "adding 4 and 5 gets: " << Add(i1, i2) << endl;
	
	// class templates accepts various types of data as well
	Complex<double> complxDbl(1.2, 2.2);
	Complex<int> complxInt(3, 4);
	cout << "real: " << complxDbl.Real << " imag: " 
		<< complxDbl.Imag << endl;
	cout << "real: " << complxInt.Real << " imag: "
		<< complxInt.Imag << endl;
	return 0;
}
