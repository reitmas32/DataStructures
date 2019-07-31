/**
  * @file    Node.hpp
  * @version 3.0
  * @date    31/07/2019
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
    Node(Item _data){
        SetData(_data);
        SetNext(NULL);
        SetPrev(NULL);
    }

    Node(){
        SetNext(NULL);
        SetPrev(NULL);
    }

    Node(Node<Item>* _other){
        SetData(_other->GetData());
        SetNext(_other->GetNext());
        SetPrev(_other->GetPrev());
    }

    //Destructor
    ~Node(){free(this)}

    //Getters
    Item  GetData(){return data;}
    Node* GetNext(){return next;}
    Node* GetPrev(){return prev;}

    //Setters
    void SetData(Item _data){data = _data;}
    void SetNext(Node* _next){next = _next;}
    void SetPrev(Node* _prev){prev = _prev;}
};

#endif //DLL_NODE_HPP

