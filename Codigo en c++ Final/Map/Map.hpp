#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../Couple/Couple.hpp"

template <typename ItemOne, typename ItemTwo>
class Map{
	private:
		Couple<ItemOne,ItemTwo> *table;
		size_t size;
		size_t len;
		ItemOne empty;
		size_t (*hash)(ItemOne key, size_t max);
		size_t (*coll_res)(size_t index, size_t max);
	public:
		Map(size_t capacity, ItemOne empty_val, size_t(*pHash)(ItemOne id, size_t max), size_t(*pCollRes)(size_t index, size_t max));
		~Map();
		bool Insert(ItemOne key, ItemTwo value);
		/*Busca una clave y regresa su value*/
		bool Retrieve(ItemOne key, ItemTwo* value);
		bool Remove(ItemOne key);
		size_t Iterator(void (*pfun)( ItemOne id, ItemTwo sueldo ));
		size_t Len();
		size_t Size();
};

template <typename ItemOne, typename ItemTwo>
Map<ItemOne,ItemTwo>::Map(size_t capacity, ItemOne empty_val, size_t(*pHash)(ItemOne id, size_t max), size_t(*pCollRes)(size_t index, size_t max)){
	table = new Couple<ItemOne,ItemTwo>[capacity];

	for(size_t i=0; i< capacity; i++){table[i].setOne(empty_val);}

	size = capacity;
	len = 0L;
	empty = empty_val;
	hash = pHash;
	coll_res = pCollRes;
}

template <typename ItemOne, typename ItemTwo>
Map<ItemOne,ItemTwo>::~Map(){
	delete[] table;
}

template <typename ItemOne, typename ItemTwo>
bool Map<ItemOne,ItemTwo>::Insert(ItemOne key, ItemTwo value){
	int h = 0;
	size_t loc = this ->hash(key,this -> size);
	int i = loc;
	static int contador = 0;

	while(this ->table[loc].getOne() != this-> empty){
		h++;
		loc = this -> coll_res(h*h,this -> size);

		if(loc == i){
			return false;
		}
	}

	if(contador <= this -> size){
		this -> table[loc].setOne(key);
		this -> table[loc].setTwo(value);
		contador++;
	}else{
		return false;
	}

	++this -> len;

	return true;
}

template <typename ItemOne, typename ItemTwo>
bool Map<ItemOne,ItemTwo>::Retrieve(ItemOne key, ItemTwo* value){
	int h=0;
	size_t start_loc = this -> hash(key,this -> size);

	size_t loc = start_loc;

	bool more_to_search = true;
	bool found;

	do{
		if(this ->table[loc].getOne() == key || this->table[loc].getOne() == this -> empty){
			more_to_search = false;
			found = this -> table[loc].getOne() == key;
		}else{
			h++;
			loc = this -> coll_res(h*h,this -> size);
		}
	}while(loc != start_loc && more_to_search == true);



	if(found == true){
		*value = this->table[loc].getTwo();
	}

	return found;
}

template <typename ItemOne, typename ItemTwo>
bool Map<ItemOne,ItemTwo>::Remove(ItemOne key){
	size_t loc = this -> hash(key,this -> size);
	size_t i = loc;
	int h= 0;
	bool done = false;

	while(this -> table[loc].getOne() != this -> empty){
		if(this ->table[loc].getOne() == key){
			this -> table[loc].setOne(this -> empty);
			--this -> len;
			done = true;
		}else{
			h++;
			loc = this -> coll_res(h*h,this -> size);
		}
	}

	return done;
}

template <typename ItemOne, typename ItemTwo>
size_t Map<ItemOne,ItemTwo>::Iterator(void (*pfun)( ItemOne id, ItemTwo sueldo )){
	size_t cnt = 0;

	for(size_t i=0; i< this -> size; ++i){
		if(this -> table[i].getOne() != this -> empty){
			pfun(this ->table[i].getOne(),this -> table[i].getTwo());
			++cnt;
		}
	}

	return cnt;
}

template <typename ItemOne, typename ItemTwo>
size_t Map<ItemOne,ItemTwo>::Len(){
	return this -> len;
}

template <typename ItemOne, typename ItemTwo>
size_t Map<ItemOne,ItemTwo>::Size(){
	return this -> size;
}
#endif