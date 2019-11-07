#ifndef  MAP_HPP
#define  MAP_HPP

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdint.h>
#include "../DLL/DLL.hpp"
#include "../Entry/Entry.hpp"
#include <string>

typedef size_t(*pHash)(string key, size_t max);

template <typename ItemOne, typename ItemTwo>
class Map{
	private:
		DLL<Entry> **table;
		size_t size;
		size_t len;
		size_t empty;
		pHash hash;
		bool Compare(Entry e1,Entry e2);
	public:
		Map(size_t capacity, size_t empty_val, pHash hash);
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