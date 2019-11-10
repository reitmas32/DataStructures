#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Map.hpp"
using namespace std;


static size_t phash( int key, size_t max )
{
	return key % max;
}


static size_t coll_res(size_t index, size_t max )
{
	 size_t new_index = (index + 1) % max;
	 return new_index;
}

void print(int a,int w){
	cout << "Key: " << a << " Value: " << w << endl << endl;
}

int main(){

	Map<int,int> *dictionary = new Map<int,int>(5,0,phash,coll_res);
	dictionary -> Insert(10,9);
	dictionary -> Insert(100,90);
	dictionary -> Iterator(print);
	cout << "===================\n";
	dictionary -> Remove(10);
	dictionary -> Iterator(print);
	delete dictionary;
	return 0;
}