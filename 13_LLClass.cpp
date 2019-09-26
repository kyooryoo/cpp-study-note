#include "13_LLClass.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
	Head = NULL;
}

void LinkedList::Print() {
	LinkedListItem *curr = Head;
	if (curr == NULL) {
		cout << "the linked list is empty!" << endl;
	} else {
		while(curr != NULL) {
			cout << curr->Number << endl;
			curr = curr->Next;
		}
	}
}

void LinkedList::Add(int number) {
	LinkedListItem *item = new LinkedListItem(number);
	if(Head == NULL) {
		Head = item;
		End = item;
	} else {
		End->Next = item;
		End = End->Next;
	}
}

LinkedListItem *LinkedList::ElementAt(int index) {
	int idx = 0;
	LinkedListItem* curr = Head;
	while(curr != NULL && idx < index) {
		curr = curr->Next;
		idx++;
	}

	if(idx != index) {
		curr = NULL;
	}

	return curr;
}

bool LinkedList::Insert(int index, int number) {
	LinkedListItem *item = new LinkedListItem(number);
	if(index == 0) {
		LinkedListItem* tmp = Head;
		Head = item;
		item->Next = tmp;

		if(End == NULL) {
			End = item;
		}

		return true;
	} else {
		LinkedListItem* prev = ElementAt(index - 1);
		if(prev != NULL) {
			LinkedListItem* tmp = prev->Next;
			prev->Next = item;
			item->Next = tmp;
			if(prev == End) {
				End = item;
			}
			return true;
		}
	return false;
	}
}

void LinkedList::Clear() {
	LinkedListItem* curr = Head;
	while(curr != NULL) {
		LinkedListItem* tmp = curr;
		curr = curr->Next;
		delete tmp;
	}
	Head = NULL;
	End = NULL;
}

bool LinkedList::Remove(int number) {
	LinkedListItem* prev = NULL;
	LinkedListItem* curr = Head;
	while(curr != NULL) {
		if(curr->Number == number) {
			if(prev == NULL) {
				Head = curr->Next;
					if(End == curr) {
						End = NULL;
					}
				delete curr;
			} else {
				prev->Next = curr->Next;
				if(End == curr)	{
					End = prev;
				}
				delete curr;
			}
			return true;
		} else {
		prev = curr;
		curr = curr->Next;
		}
	}
	return false;
}

LinkedList::~LinkedList() {
	Clear();
}
