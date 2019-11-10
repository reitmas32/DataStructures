#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

typedef int Item;
typedef Item* ItemPtr;

class Node{
	public:
		Item data;
		Node *next;
		Node *prev;
		Node(Item);
};

typedef Node* NodePtr;

class DLL{
	private:
		NodePtr first;
		NodePtr last;
		NodePtr cursor;
		size_t len;
		void reset();
	public:
		DLL();
		~DLL();
		bool InsertBack(Item);
		bool InsertFront(Item);
		bool InsertAfter(Item);
		bool InsertBefore(Item);
		bool Remove(ItemPtr);
		bool RemoveFront(ItemPtr);
		bool RemoveBack(ItemPtr);
		bool RemoveAfter(ItemPtr);
		bool RemoveBefore(ItemPtr);
		size_t Len();
		bool IsEmpty();
		void MakeEmpty();
		bool Peek(ItemPtr);
		void CursorFirst();
		void CursorLast();
		void CursorNext();
		void CursorPrev();
		bool FindIf(Item,bool(*)(Item,Item));
		bool Search(Item,bool(*)(Item,Item));
		void Traverse(void(*)(Item));
};
#endif