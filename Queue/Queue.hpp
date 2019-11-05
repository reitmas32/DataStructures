/**
 * @file    Queue.hpp
 * @version 1.0
 * @date    13/07/2019.
 * @author  Zamora Ramírez Oswaldo Rafael
 * @brief   Es la API de una Queue plantilla
 * @code
 
    #include <iostream>

    #include "Queue.hpp"
    #include "Queue.cpp"

    using namespace std;

    int main() {
        Queue<int> miQueue(5);
        miQueue.Enqueue(3);
        int tmp;
        miQueue.Dequeue(&tmp);
        cout<<tmp<<endl;
        return 0;
    }
 * @endcode 
 */

#ifndef QUEUE_QUEUE_HPP
#define QUEUE_QUEUE_HPP

//Biblioteca para el uso de size_t
#include <cstdio>
//Biblioteca para el uso de memoria dinamica
#include <stdlib.h>

//Clase plantilla en de la Queue
template <class Item>
class Queue {
private:
    //Atributos
    Item* queue;      
    size_t front{};    
    size_t back{};     
    size_t len{};      
    size_t capacity{}; 

    //Getters
    Item* getQueue()     const{ return queue;}
    size_t getFront()    const{ return  front;}
    size_t getBack()     const{ return back;}
    size_t getLen()      const{ return len;}
    size_t getCapacity() const{ return capacity;}

    //Setters
    void setQueue(Item* _queue){ queue = _queue;}
    void setFront(size_t _front){ front = _front;}
    void setBack(size_t _back){ back = _back;}
    void setLen(size_t _len){ len = _len;}
    void setCapacity(size_t _capacity){ capacity = _capacity;}

public:

    //Constructoe
    Queue(size_t _capacity);

    //Destructor
    ~Queue();

    //Metodos
    bool Enqueue(Item _data);
    bool Dequeue(Item* _data_back);
    bool Peek(Item* _data_back);
    bool IsEmpty();
    bool IsFull();
    size_t Len();
    size_t Capacity();
    void MakeEmpty();
};


#endif //QUEUE_QUEUE_HPP
