/**
  * @file    Node.cpp
  * @version 2.0
  * @date    17/07/2019
  * @author  Zamora Ramírez Oswaldo Rafael
  * @brief   API del Nodo de una DLL de tipos dinamicos
*/

#include "Node.hpp"

//Constructor
template<class Item>
Node<Item>::Node(Item _data){
    data = _data;
    next = NULL;
    prev = NULL;
}

//Destructor
template<class Item>
Node<Item>::~Node(){
    free(this);
}

//Getters
template<class Item>
Item Node<Item>::getData(){
    return data;
}

template<class Item>
Node<Item>* Node<Item>::getNext(){
    return next;
}

template<class Item>
Node<Item>* Node<Item>::getPrev(){
    return prev;
}

//Setters
template<class Item>
void Node<Item>::setData(Item _data){
    data = _data;
}

template<class Item>
void Node<Item>::setNext(Node* _next){
    next = _next;
}

template<class Item>
void Node<Item>::setPrev(Node* _prev){
    prev = _prev;
}
