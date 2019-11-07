#ifndef  MAP_HPP
#define  MAP_HPP

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdint.h>
#include "../DLL/DLL.hpp"
#include "../Couple/Couple.hpp"
#include <string>

typedef size_t(*pHash)( string key, size_t max);

template <typename ItemOne, typename ItemTwo>
class Map{
	private:
		Couple<ItemOne, ItemTwo> *table;
		size_t size;
		size_t len;
		size_t empty;
		pHash hash;
	public:
		Map(size_t capacity, Couple<ItemOne,ItemTwo> empty_val);
		~Map();
		bool Insert(ItemOne key, ItemTwo value);
		bool Retrieve(ItemOne key, ItemTwo *value);
		bool Remove(ItemOne key);
		size_t Iterator(void(*pfun)(ItemOne key, ItemTwo value));
		size_t getLen();
		size_t getSize();
		ItemTwo getItemTwo(ItemOne key);
		void printValues();
};

#endif
