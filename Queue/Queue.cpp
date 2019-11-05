//
// Created by rafaz on 13/07/2019.
//

#include "Queue.hpp"

//Constructoe
template<class Item>
Queue<Item>::Queue(size_t _capacity){
    setQueue((Item*)calloc(_capacity, sizeof(Item)));
    setCapacity(_capacity);
    setLen(0);
    setFront(0);
    setBack(0);
}

//Destructor
template<class Item>
Queue<Item>::~Queue(){
    free(getQueue());
    free(this);
}

//Metodos
template<class Item>
bool Queue<Item>::Enqueue(Item _data){
    bool done = false;
    if(getFront()<getCapacity()){
        done = true;
        getQueue()[getBack()] = _data;
        setBack(getBack()+1);
        setLen(getLen()+1);
    }
    return done;
}

template<class Item>
bool Queue<Item>::Dequeue(Item* _data_back){
    bool done = false;
    if(!IsEmpty()){
        done = true;
        *_data_back = getQueue()[getFront()];
        setFront(getFront()+1);
        setLen(getLen()+1);
    }
    return done;
}

template<class Item>
bool Queue<Item>::Peek(Item* _data_back){
    bool done = false;
    if(!IsEmpty()){
        done = true;
        *_data_back = getQueue()[getFront()];
    }
    return done;
}

template<class Item>
bool Queue<Item>::IsEmpty(){
    return getLen() == 0;
}

template<class Item>
bool Queue<Item>::IsFull(){
    return getLen() + 1 == getCapacity();
}

template<class Item>
size_t Queue<Item>::Len(){
    return getLen();
}

template<class Item>
size_t Queue<Item>::Capacity(){
    return getCapacity();
}

template<class Item>
void Queue<Item>::MakeEmpty(){
    setLen(0);
    setCapacity(0);
    setBack(0);
}
