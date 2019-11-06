//
// Created by Oswaldo Rafael Zamora Ramírez on 13/07/2019.
//

#include <iostream>

#include "Stack.hpp"

//Constructor
template<class Item>
Stack<Item>::Stack(size_t _capacity){

    setStack((Item*)calloc(_capacity, sizeof(Item)));

    setCapacity(_capacity);

    setTop(0);

}

//Destructor
template<class Item>
Stack<Item>::~Stack(){
    free(this);
}

//Metodos
template<class Item>
bool Stack<Item>::Push(Item _data){
    bool done = false;
    if(getTop()<getCapacity()){
        done = true;
        getStack()[getTop()] = _data;
        setTop(getTop()+1);
    }
    return done;
}

template<class Item>
bool Stack<Item>::Pop(Item* _data_back){
    bool done = false;

    if(!IsEmpty()){
        done = true;
        setTop(getTop()-1);
        *_data_back = getStack()[getTop()];
    }
    return done;
}

template<class Item>
bool Stack<Item>::Peek(Item* _data_back){
    bool done = false;
    if(!IsEmpty()){
        done = true;
        *_data_back = getStack()[getTop()-1];
    }
    return done;
}

template<class Item>
size_t Stack<Item>::Len(){
    return getTop()+1;
}

template<class Item>
size_t Stack<Item>::Capcity(){
    return getCapacity();
}

template<class Item>
bool Stack<Item>::IsEmpty(){
    return getTop() == 0;
}

template<class Item>
void Stack<Item>::MakeEmpty(){
    Item tmp;
    for(size_t i = 0; i <= getTop(); i++){
        Push(&tmp);
    }
}