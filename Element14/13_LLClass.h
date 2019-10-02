#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListItem {
	int Number;
	LinkedListItem *Next;
	
	LinkedListItem(int number) {
		Number = number;
		Next = NULL;
	}
} LinkedListItem;

class LinkedList {
	public:
		LinkedListItem *Head;
		LinkedListItem *End;
		
		LinkedList();
		~LinkedList();
		
		void Print();
		void Add(int number);
		LinkedListItem* ElementAt(int index);
		bool Insert(int index, int number);
		void Clear();
		bool Remove(int number);
};

#endif
