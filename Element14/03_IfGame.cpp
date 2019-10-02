// pay attention to:
// * if statement
// * how to generate a random number
// * random number with limit digit or range

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
	unsigned int timestamp = time(NULL);
	//cout << "the timestamp seed is: " << timestamp << endl;

	srand(timestamp);
	int num = rand();
	//cout << "the random number is: " << num << endl;

	num = num % 7 + 1;
	//cout << "the target number is: " << num << endl;
	
	int guess = 0;
	cout << "guess a number between 1 and 7: " << endl;
	cin >> guess;
	
	if (guess == num) {
		cout << "you win!" << endl;
	} else if (guess < num) {
		cout << "your guess is less!" << endl;
	} else {
		cout << "your guess is greater!" << endl;
	}
	
	return 0;
}
