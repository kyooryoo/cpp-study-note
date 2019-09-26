#include <iostream>
using namespace std;

#include "13_LLClass.h"

int main() {
	LinkedList LL;
	
	cout << "initilize a liked list with 1, 2, and 3:" << endl;
	LL.Add(1);
	LL.Add(2);
	LL.Add(3);
	LL.Print();
	
	cout << "the element at index 1 of the linked list:" << endl;
	LinkedListItem* LLI = LL.ElementAt(1);
	cout << LLI->Number << endl;
	
	cout << "insert number 4 at index 1 of the linked list:" << endl;
	LL.Insert(1, 4);
	LL.Print();
	
	cout << "remove number 3 from the linked list:" << endl;
	LL.Remove(3);
	LL.Print();
	
	cout << "clear the linked list:" << endl;
	LL.Clear();
	LL.Print();
	
	return 0;
}
