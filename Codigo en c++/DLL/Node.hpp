/**
  * @file    Node.hpp
  * @version 2.0
  * @date    17/07/2019
  * @author  Zamora Ramírez Oswaldo Rafael
  * @brief   API del Nodo de una DLL de tipos dinamicos
*/

#ifndef DLL_NODE_HPP
#define DLL_NODE_HPP

#include <iostream>

template <class Item>
class Node{
private:
    Item data;
    Node* next;
    Node* prev;
public:
    //Constructor
    Node(Item _data);

    //Destructor
    ~Node();

    //Getters
    Item getData();
    Node* getNext();
    Node* getPrev();

    //Setters
    void setData(Item _data);
    void setNext(Node* _next);
    void setPrev(Node* _prev);
};

#endif //DLL_NODE_HPP
