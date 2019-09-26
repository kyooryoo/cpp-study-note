#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int numSubjects = 4;
string subjects[] = {
	"The universe",
	"I",
	"The man in the white hat",
	"A garden gnome"
};

int numVerbs = 2;
string verbs[] = {
	"wants",
	"loves"
};

int numComplements = 4;
string complements[] = {
	"string cheese",
	"cake",
	"bicycles",
	"a Raspberry Pi"
};

int numCanned = 5;
string canned[] = {
	"Why not?",
	"I said so",
	"C++ is the greatest language of all time",
	"That is how he wants it",
	"Boom goes the dynamite"
};

string why() {
	int chance = rand() % 10;
	string sentence;
	if(chance < 7) {
		string subject = subjects[rand() % numSubjects];
		string verb = verbs[rand() % numVerbs];
		string complement = complements[rand() % numComplements];
		sentence = subject + " " + verb + " " + complement;
	} else {
		sentence = canned[rand() % numCanned];
	}
	return sentence;
}

int main() {
	srand((unsigned int) time(NULL));
	cout << "the why() game: ";
	cout << why() << endl;
	
	string CreateString("A string");
	string AnotherString = "Another String"; 
	cout << "both '" << CreateString << "' and '" << AnotherString 
		<< "' are legal strings!" << endl;
		
	string aString = "aString";
	string AString = "AString";
	if (aString == AString) {
		cout << "'aString' is equal to 'AString'!" << endl;	
	} else if (aString > AString) {
		cout << "'aString' is greater than 'AString'!" << endl;	
	} else if (aString < AString) {
		cout << "'aString' is less than 'AString'!" << endl;	
	} else {
		cout << "you cannot compare aString with 'AString'!" << endl;
	}
	
	string greeting = "Hello ";
	string name = "friend";
	cout << "add two strings: " << greeting + name << endl;
	cout << "append two strings: " << greeting.append(name) << endl;
	
	return 0;
}
