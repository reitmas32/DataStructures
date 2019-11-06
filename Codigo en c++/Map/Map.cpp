#include "Map.hpp"

template <typename ItemOne, typename ItemTwo>
bool Map<ItemOne,ItemTwo>::Compare(Entry e1,Entry e2){
	if(e1.key.compare(e2.key) == 0){
		return true;
	}

	return false;
}
template <typename ItemOne, typename ItemTwo>
Map<ItemOne,ItemTwo>::Map(size_t capacity, size_t empty_val, pHash hash){
	this -> table = new DLL<Entry*>();

	for(size_t i = 0; i <capacity; ++i){table[i] = new DLL<Entry*>;}

		this -> size = capacity;
		this -> len = 0L;
		this -> empty = empty_val;
		this -> hash = hash;
}
template <typename ItemOne, typename ItemTwo>
Map<ItemOne,ItemTwo>::~Map(){
	assert(this);

	for(size_t i = 0; i < this -> size; ++i){
		table[i] -> ~DLL();
	}

	delete(this);
}
template <typename ItemOne, typename ItemTwo>
bool Map<ItemOne,ItemTwo>::Insert(ItemOne key, ItemTwo value){
	size_t loc = this -> hash(key,this -> size);
	Entry tmp;
	tmp.key = key;
	tmp.value = value;
	bool done = false;

	if(table[loc] -> InsertBack(&tmp)){
		done = true;
		++this -> len;
	}

	return done;
}
template <typename ItemOne, typename ItemTwo>
bool Map<ItemOne,ItemTwo>::Retrieve(ItemOne key, ItemTwo *value){
	size_t loc = this->hash(key,this -> size);

	Entry Item;
	Item.key = key;

	bool found = this -> table[loc] -> FindIf(&Item,Compare);

	if(found == true){
		*value = Item.value;
	}

	return found;
}
template <typename ItemOne, typename ItemTwo>
bool Map<ItemOne,ItemTwo>::Remove(ItemOne key){
	size_t loc = this -> hash(key,this -> size);
	Entry *tmp;
	tmp -> key = key;

	if(this -> table[loc] -> Search(&tmp,Compare)){
		if(this -> table[loc] -> Remove(&tmp)){
			--this -> len;
			return true;
		}
	}

	return false;
}

template <typename ItemOne, typename ItemTwo>
size_t Map<ItemOne,ItemTwo>::Iterator(void(*pfun)(ItemOne key, ItemTwo value)){
	
	size_t cnt = 0;

	for( size_t i = 0; i < this->size; ++i ){
		for(Node<Entry*> *it = this -> table[i]-> first; it != NULL; it = it -> next){
			++cnt;
			pfun( it-> data -> key, it -> data -> value );
		}
	}
		
	return cnt;
}
template <typename ItemOne, typename ItemTwo>
size_t Map<ItemOne,ItemTwo>::getLen(){
	return len;
}
template <typename ItemOne, typename ItemTwo>
size_t Map<ItemOne,ItemTwo>::getSize(){
	return size;
}