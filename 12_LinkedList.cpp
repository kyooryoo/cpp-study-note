// linked list is constructed with value and pointer pairs
// suitable for storing data with unknown number of items
// does not require sequential block of memory like an array
// performance is not good for retrieving data randomly
#include <iostream>
using namespace std;

typedef struct LinkedListItem {
	int Number;
	LinkedListItem *Next;
	
	LinkedListItem(int number) {
		Number = number;
		Next = NULL;
	}
} LinkedListItem;

void Print(LinkedListItem *head) {
	LinkedListItem *curr = head;
	while(curr != NULL) {
		cout << curr->Number << endl;
		curr = curr->Next;
	}
}

int main() {
	LinkedListItem *head = NULL;

	head = new LinkedListItem(1);
	(*head).Next = new LinkedListItem(2);
	(*(*head).Next).Next = new LinkedListItem(3);
	
	Print(head);
	return 0;
}
