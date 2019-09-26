// pay attention to:
// * define func out of main
// * the usage of recursion

#include <iostream>
using namespace std;

// factorial calculates n*(n-1)*...2*1
int ForFactorial(int n) {
	int result = 1;
	for(int i = 1; i <= n; i++) {
		result = result * i;
	}
	return result;
}

// factorial in recursion way
int RecFactorial(int n) {
	if(n < 2) {
		return 1;
	}
	return n * RecFactorial(n - 1);
}

// number of the combination of n out of m
int main() {
	int m = 0;
	cout << "the total number of elements: ";
	cin >> m;
	
	int n = 0;
	cout << "the number of elements you choose: ";
	cin >> n;
	
	int forComb = ForFactorial(m)/(ForFactorial(n)*ForFactorial(m-n));
	int recComb = RecFactorial(m)/(RecFactorial(n)*RecFactorial(m-n));

	cout << "the # of combination from for loop is " << forComb << endl;
	cout << "the # of combination from recursion is " << recComb << endl;
	return 0; 
}
