// this program creates random number per request
// the length of the random number array is dynamic

// pay attention to:
// * how to define a method for creating dynamic array
// * how to create a dynamic array with new
// * remember to delete the dynamic arry for freeing memory

#include <iostream>
#include <ctime>
using namespace std;

// following is a bad implementation
// it creates an array with new but cannot delete it
// for cleaning up the memory that it allocated
// create the array outside of the function that pass it in
int* RandArray(int length) {
	int* vector = new int[length];
	for(int i = 0; i < length; i++) {
		vector[i] = (rand() % 10) + 1;
	}
	return vector;
}

// following func does not create the array
// and thus does not need to clean up the memory
void RandArray(int* vector, int length) {
	for(int i = 0; i < length; i++) {
		vector[i] = (rand() % 10) + 1;
	}
}

int main() {
	// generate random seed from the timestamp
	srand((unsigned int) time(NULL));

	int length;
	cout << "how many random number do you want? ";
	cin >> length;

	// create a dynamic array
	int* vector = new int[length]();
	RandArray(vector, length);

	cout << "the reandom numbers are as follows:" << endl;
	for(int i = 0; i < length; i++) {
		cout << vector[i] << " ";
	}

	// delete the object for freeing up memory
	delete[] vector;
	return 0;
}
