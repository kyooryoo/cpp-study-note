// pay attention to:
// * review if statement
// * review user input method
// * the for statement
// * how to compare strings
// * the use of return

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	// generate a random number between 1 and 7
	srand((unsigned int) time(NULL));
	int num = rand() % 7 + 1;

	// for debugging purpose:
	//cout << "the target number is: " << num << endl;
	
	// Game intro and setup
	string will = "";
	cout << "play the game to guess a number?" << endl;
	cin >> will;
	
	// opt in or out of the game
	int guess = 0;
	if (will == "no") {
		cout << "ok, come back if you want to play" << endl;
		return 0;
	} else {
		int num_guesses = 0;
		cout << "how many times do you want to guess?" << endl;
		cin >> num_guesses;
		// iterate through the game as the player wishes
		for (int i = 0; i < num_guesses; i++) {
			cout << "guess one number between 1 and 7: ";
			cin >> guess;
			if (guess == num) {
				cout << "correct, the number was " << num << endl;
				return 0;
			} else if (guess < num) {
				cout << "your guess is less!" << endl;
			} else {
				cout << "your guess is greater!" << endl;
			}
		}
	}
	
	cout << "you lose, the correct number was " << num << endl; 
	return 0;
}
