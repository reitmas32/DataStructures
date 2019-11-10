#include <iostream>
#include "Map.hpp"

size_t h( std::string key, size_t max){

    uint32_t key_32 = 0;

    for (size_t i = 0; i < key.length(); i++)
    {
        key_32 += (uint32_t)key[i];
    }
    
    return key_32 % max;
}

bool compare(Couple<std::string,int> first, Couple<std::string,int> second){
    return first.key == second.key ? true : false;
}

int main()
{
    int y = 0;
    Map<std::string,int>* m = new Map(16,{"",0}, h, compare);
    m->Insert("hola", 15);
    m->Insert("hol", 5);
    
    m->Insert("Qu",9);
    m->Retrieve("hola", &y);
    std::cout<<m->getLen()<<std::endl;
    m->printValues();
    //m->~Map();
    return 0;
}
