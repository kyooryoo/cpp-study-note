// this is a revised version of 04_ForGame.cpp
// pay attention to:
// * #include <limits> for using numeric_limits
// * the added while loop to validate user input
// * the if statement within while loop

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string.h>
#include <limits>
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
	if (will == "no") {
		cout << "ok, come back when you want to play" << endl;
		return 0;
	} else {
		int num_guesses = 0;
		cout << "how many times do you want to guess?" << endl;
		cin >> num_guesses;
		// iterate through the game as the player wishes
		for (int i = 0; i < num_guesses; i++) {
			int guess = 0;
			while (guess < 1 || guess > 7) {
				cout << "guess one number between 1 and 7: ";
				cin >> guess;
				if(cin.gcount() != 1 || guess < 1 || guess > 7) {
					cout << "please input a proper number!" << endl;
					cin.clear();
					cin.ignore(numeric_limits<int>::max(), '\n');
				}
			}
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
