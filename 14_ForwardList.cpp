// list and vector are Linked List implementation by SLT
// forward list, list, and vector are suitable for # unknown elements
// elements could be pushed from front or back, and iterate through itr
#include <iostream>
#include <forward_list>
#include <list>
#include <vector>

using namespace std;

void print1(forward_list<int> list) {
	//for(forward_list<int>::iterator itr = list.begin(); itr != list.end(); itr++) {
	// know the background and use `auto` for saving the complex input
	for(auto itr = list.begin(); itr != list.end(); itr++) {
		cout << *itr << endl;
	}
}

void print2(list<int> list) {
	// the iterator could be used for forward 
	for(auto itr = list.begin(); itr != list.end(); itr++) {
		cout << *itr << endl;
	}
}

void print3(vector<int> vector) {
	for(auto itr = vector.begin(); itr != vector.end(); itr++) {
		cout << *itr << endl;
	}
}

// vector could be treated like an array
void print4(vector<int> vector) {
	for(unsigned int i = 0; i < vector.size(); i++ ) {
		cout << vector[i] << endl;
	}
}

int main() {
	// forward list has links to after elements
	forward_list<int> flist;
	flist.push_front(1);
	flist.push_front(2);
	cout << "forward list after push front of 1 and 2:" << endl;
	print1(flist);

	// list is double linked to both before and after elements
	list<int> list;
	list.push_front(3);
	list.push_back(4);
	list.push_front(5);
	list.push_back(6);
	cout << "list with push of front 3, back 4, ";
	cout << "front 5, and back 6:" << endl;
	print2(list);
	
	// vector uses dynamic array in the background
	vector<int> vector;
	vector.push_back(7);
	vector.push_back(8);
	cout << "vector after back push of 7 and 8:" << endl;
	cout << "print from vector iterator: " << endl;
	print3(vector);
	cout << "print vector as an array: " << endl;
	print4(vector);
	
	return 0;
}
