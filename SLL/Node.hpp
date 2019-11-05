/**
  * @file    Node.hpp
  * @version 2.0
  * @date    14/07/2019
  * @author  Zamora Ramírez Oswaldo Rafael
  * @brief   API del Nodo de una SLL de tipos dinamicos
*/

#ifndef SLL_NODE_HPP
#define SLL_NODE_HPP

#include <iostream>

template <class Item>
class Node{
private:
    Item data;
    Node* next;
public:
    //Constructor
    Node(Item _data);

    //Destructor
    ~Node();

    //Getters
    Item getData();
    Node* getNext();

    //Setters
    void setData(Item _data);
    void setNext(Node* _next);
};

#endif //SLL_NODE_HPP
