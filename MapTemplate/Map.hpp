#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <stdlib.h>
#include "DLL.hpp"

typedef std::string Key;
typedef int Value;

template<typename First, typename Second> 
struct Couple
{
    First key;
    Second value;
};

template<typename Key, typename Value> 
class Map{
private:
    DLL<Couple<Key,Value>>** table;
    size_t len;
    Couple<Key,Value> empty_val;
    size_t(*pHash)( Key key, size_t max);
    bool(*compare)(Couple<Key,Value> first, Couple<Key,Value> second);
    size_t capacity;
public:
    Map(/* args */);
    Map(size_t capacity, Couple<Key,Value> empty_val,size_t(*pHash)( Key key, size_t max),bool(*compare)(Couple<Key,Value> first, Couple<Key,Value> second));
    ~Map();

    bool Insert(Key key, Value value);
    bool Search(Key key);
    bool Retrieve(Key key, Value *value);
    bool Remove(Key key);
    size_t Iterator(void(*pfun)(Key key, Value value));
    size_t getLen(){return this->len;}
    size_t getSize(){return this->capacity;}
    Value getItemTwo(Key key);
    void printValues();

};

template<typename Key, typename Value> 
Map<Key,Value>::Map(size_t capacity, Couple<Key,Value> empty_val,size_t(*pHash)( Key key, size_t max),bool(*compare)(Couple<Key,Value> first, Couple<Key,Value> second)){

    this->table = (DLL<Couple<Key,Value>>**)calloc(capacity, sizeof(DLL<Couple<Key,Value>>*));
    for(size_t i = 0; i < capacity; i++){
        this->table[i] = new DLL<Couple<Key,Value>>();
    }
    
    if(this->table != NULL){
        this->len = 0;
        this->capacity = capacity;
        this->empty_val = empty_val;
        this->pHash = pHash;
        this->compare = compare;
    }
    
}

template<typename Key, typename Value> 
Map<Key,Value>::~Map()
{
    //free(this->table);
    //delete(this);
}

template<typename Key, typename Value> 
bool
Map<Key,Value>::Insert(Key key,Value value){
    bool done = false;
    size_t loc = this->pHash(key,this->capacity);
    Couple<Key,Value> tmp;
    this->table[loc]->CursorFirst();
    this->table[loc]->Peek(&tmp);
    if(tmp.key == this->empty_val.key){

        Couple<Key,Value> tmp = {key,value};
        this->table[loc]->InsertBack(tmp);
        len++;
        done = true;
    }
    
    return done;
}
template<typename Key, typename Value> 
bool
Map<Key,Value>::Retrieve(Key key, Value* value){
    size_t loc = this->pHash(key,this->capacity);
    Couple<Key,Value> Item;
    Item.key = key;

    bool found = this->table[loc]->Search(Item,this->compare);
    if(found){
        this->table[loc]->Peek(&Item);
        *value = Item.value;
    }
    return found;
}
template<typename Key, typename Value> 
bool
Map<Key,Value>::Remove(Key key){
    size_t loc = this->pHash(key,this->capacity);
    Couple<Key,Value> Item;
    Item.key = key;

    bool found = this->table[loc]->Search(Item,this->compare);
    if(found){
        this->table[loc]->Remove(&Item);
    }
    return found;
}
template<typename Key, typename Value> 
bool
Map<Key,Value>::Search(Key key){
    bool found = false;
    for (size_t i = 0; i < this->capacity; i++)
    {
        Couple<Key,Value> tmp;
        this->table[i]->CursorFirst();
        this->table[i]->Peek(&tmp);
        if(tmp.key == key){
            found = true;
            break;
        }
    }
    return found;
}
template<typename Key, typename Value> 
void 
Map<Key,Value>::printValues(){
    for(size_t i = 0; i < this->capacity; i++){
        if(not this->table[i]->IsEmpty()){
            Couple<Key,Value> tmp;
            this->table[i]->CursorFirst();
            for(;this->table[i]->getCursor() != NULL; this->table[i]->CursorNext() ){
                this->table[i]->Peek(&tmp);
                std::cout<<"Key: "<<tmp.key<<" Value: "<<tmp.value<<std::endl;
            }
        }
        
    }
}

#endif  //MAP_HPP