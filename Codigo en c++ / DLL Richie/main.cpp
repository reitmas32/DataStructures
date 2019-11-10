#include "DLL.hpp"

void print(Item obj){
	cout << obj << endl;
}

int main(){

	DLL *list = new DLL();

	list -> InsertBack(100);
	list -> InsertBack(101);
	list -> InsertBack(102);
	list -> InsertBack(103);
	list -> InsertBack(104);
	list -> InsertBack(105);
	list -> InsertBack(106);
	list -> InsertBack(107);

	list -> CursorFirst();
	list -> CursorNext();
	list -> InsertBefore(99);

	list -> Traverse(print);
	delete list;

}