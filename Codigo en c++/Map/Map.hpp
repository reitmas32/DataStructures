#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include "../Couple/Couple.hpp"

template <typename ItemOne, typename ItemTwo>
class Map{
	private:
		Couple<ItemOne,ItemTwo> *table;
		size_t size;
		size_t len;
		ItemOne empty;
		typedef size_t (*pHash)(size_t key, size_t max);
		typedef size_t (*pCollRes)( size_t index, size_t max);
		pHash hash;
		pCollRes coll_res;
	public:
		Map();
		~Map();

};
#endif