#include "DLL.hpp"

Node::Node(Item _data){
	data = _data;
	next = NULL;
	prev = NULL;
}

void DLL::reset(){
	first = last = cursor = NULL;
	len = 0;
}

DLL::DLL(){
	reset();
}

DLL::~DLL(){
	MakeEmpty();
	cout << "Se elimino la DLL" << endl;
}

bool DLL::InsertBack(Item _data){
	bool done = false;
	NodePtr n = new Node(_data);

	if(n){
		done = true;

		if(IsEmpty()){
			first = last = cursor = n;
			len = 1;
		}else{
			last -> next = n;
			n -> prev = last;
			last = n;
			len++;
		}

	}

	return done;
}

bool DLL::InsertFront(Item _data){
	bool done = false;

	NodePtr n = new Node(_data);

	if(n){
		done = true;

		if(IsEmpty()){
			first = last = cursor = n;
			len = 1;
		}else{
			n -> next = first;
			first -> prev = n;
			first = n;
			len++;
		}
	}

	return done;

}

bool DLL::InsertAfter(Item _data){
	bool done = false;

	if(IsEmpty() || cursor == last){
		done = InsertBack(_data);
	}else{
		NodePtr n = new Node(_data);

		if(n){
			done = true;

			n -> next = cursor -> next;
			cursor -> next -> prev = n;
			cursor -> next = n;
			n -> prev = cursor;
			len++;
		}
	}

	return done;
}

bool DLL::InsertBefore(Item _data){
	bool done = false;

	if(IsEmpty() || cursor == first){
		done = InsertFront(_data);
	}else{
		NodePtr n = new Node(_data);

		if(n){
			done = true;
			n -> prev = cursor -> prev;
			cursor -> prev -> next = n;
			cursor -> prev = n;
			n -> next = cursor;
			len++;
		}
	}

	return done;

}

bool DLL::Remove(ItemPtr _data_back){
	bool done = false;

	if(!IsEmpty() && NULL != cursor){
		done = true;

		if(cursor == first){
			RemoveFront(_data_back);
		}else if(cursor == last){
			RemoveBack(_data_back);
		}else{
			*_data_back = cursor -> data;

			NodePtr left = cursor -> prev;

			NodePtr right = cursor -> next;

			delete cursor;

			if(left == NULL && right == NULL){
				reset();
			}else{
				cursor = left;
				cursor -> next = right;
				right -> prev = cursor;
				len--;
			}
		}
	}

	return done;

}

bool DLL::RemoveFront(ItemPtr _data_back){
	bool done = false;

	if(!IsEmpty()){
		done = true;

		*_data_back = first -> data;

		NodePtr tmp = first -> next;
		delete first;
		first = tmp;

		if(NULL != first){
			first -> prev = NULL;
			len--;
		}else{
			reset();
		}
	}

	return done;

}

bool DLL::RemoveBack(ItemPtr _data_back){
	bool done = false;

	if(!IsEmpty()){
		done = true;

		*_data_back = last -> data;
		NodePtr tmp = last -> prev;
		delete last;
		last = tmp;

		if(NULL != last){
			last -> next = NULL;
			len--;
		}else{
			reset();
		}
	}

	return done;
}

bool DLL::RemoveAfter(ItemPtr _data_back){
	bool done = false;

	if(!IsEmpty() && cursor != last && cursor != NULL){
		done = true;
		NodePtr tmp1 = cursor -> next;
		*_data_back = tmp1 -> data;
		NodePtr tmp2 = tmp1 -> next;
		delete tmp1;
		cursor -> next = tmp2;

		if(tmp2 != NULL){
			tmp2 -> prev = cursor;
		}else{
			last = cursor;
		}
		len--;
	}

	return done;
}

bool DLL::RemoveBefore(ItemPtr _data_back){
	bool done = false;

	if(!IsEmpty() && cursor != first && cursor != NULL){
		done = true;
		NodePtr tmp1 = cursor -> prev;
		*_data_back = tmp1 -> data;
		NodePtr tmp2 = tmp1 -> prev;
		delete tmp1;
		cursor -> prev = tmp2;

		if(tmp2 != NULL){
			tmp2 -> next = cursor;
		}else{
			first = cursor;
		}
		len--;
	}
	return done;
}

size_t DLL::Len(){
	return len;
}

bool DLL::IsEmpty(){
	return first == NULL;
}

void DLL::MakeEmpty(){
	while(NULL != first){
		NodePtr tmp = first -> next;
		delete first;
		first = tmp;
	}

	reset();
}

bool DLL::Peek(ItemPtr _data_back){
	bool done = false;

	if(!IsEmpty() && cursor != NULL){
		*_data_back = cursor -> data;
		done = true;
	}

	return done;

}

void DLL::CursorFirst(){
	cursor = first;
}

void DLL::CursorLast(){
	cursor = last;
}

void DLL::CursorNext(){
	if(cursor != NULL){
		cursor = cursor -> next;
	}
}

void DLL::CursorPrev(){
	if(cursor != NULL){
		cursor = cursor -> prev;
	}
}

bool DLL::FindIf(Item _key, bool(*cmp)(Item,Item)){
	bool found = false;

	for(NodePtr it = first; it != NULL; it = it -> next){
		if(cmp(_key, it -> data)){
			found = true;
			break;
		}
	}

	return found;
}

bool DLL::Search(Item _key, bool (*cmp)(Item,Item)){
	bool found = false;

	if(!IsEmpty()){

		for(NodePtr it = first; it != NULL; it = it -> next){

			if(cmp(_key, it -> data)){
				found = true;
				cursor = it;
				break;
			}
		}
	}

	return found;
}

void DLL::Traverse(void (*pfun)(Item)){

	for(NodePtr it = first; it != NULL; it = it -> next){
		pfun(it -> data);
	}
}


