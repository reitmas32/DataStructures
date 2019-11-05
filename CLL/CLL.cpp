/**
  * @file    CLL.cpp
  * @version 2.0
  * @date    14/07/2019
  * @author  Zamora Ramírez Oswaldo Rafael
  * @brief   API de una CLL de tipos dinamicos
*/


#include "CLL.hpp"

//Constructor
template <class Item>
CLL<Item>::CLL(){
    setFirst(NULL);
    setCursor(NULL);
    setLast(NULL);
    setLen(0);
}

//Destructor
template <class Item>
CLL<Item>::~CLL(){
    MakeEmpty();
    free(this);
}

//Insert
template <class Item>
bool    CLL<Item>::InsertBack(  Item _data ){
    bool done = false;
    auto* n = new Node<Item>(_data);
    if(n){
        done = true;
        if(IsEmpty()){
            setFirst(n);
            setLast(n);
            getLast()->setNext(getFirst());
        }
        else{
            getLast()->setNext(n);
            setLast(n);
            getLast()->setNext(getFirst());
        }
        lenUp();
    }
    return done;
}

template <class Item>
bool CLL<Item>::InsertAfter( Item _data ){
    bool done = false;
    auto* n = new Node<Item>(_data);
    if(n){
        done = true;
        if(IsEmpty()){
            setFirst(n);
            setLast(n);
            getLast()->setNext(getFirst());
        }
        else{
            if(getCursor()==getLast()){
                InsertBack(_data);
            }
            else{
                n->setNext(getCursor()->getNext());
                getCursor()->setNext(n);
            }
        }
        lenUp();
    }
    return done;
}

template <class Item>
bool    CLL<Item>::InsertFront( Item _data ){
    bool done = false;
    auto* n = new Node<Item>(_data);
    if(n){
        done = true;
        if(IsEmpty()){
            setFirst(n);
            setLast(n);
            getLast()->setNext(getFirst());
        }
        else{
            n->setNext(getFirst());
            setFirst(n);
            getLast()->setNext(getFirst());
        }
        lenUp();
    }
    return done;
}

//Remove
template <class Item>
bool    CLL<Item>::RemoveFront(Item* _data_back ){
    bool done = false;
    if(!IsEmpty()){
        done = true;
        *_data_back = getFirst()->getData();
        Node<Item>* tmp = getFirst();
        getFirst()->~Node();
        setFirst(tmp);
        getLast()->setNext(getFirst());
        lenDown();
    }
    return done;
}

//Peek
template <class Item>
bool    CLL<Item>::Peek(Item* _data_back ){
    bool done = false;
    if(!IsEmpty() && getCursor()!=NULL){
        done = true;
        *_data_back = getCursor()->getData();
    }
    return done;
}

//Otros
template <class Item>
size_t  CLL<Item>::Len(){
    return getLen();
}

template <class Item>
bool    CLL<Item>::IsEmpty(){
    return getLen() == 0;
}

template <class Item>
void    CLL<Item>::MakeEmpty(){
    Item tmp;
    while (!IsEmpty()){
        RemoveFront(&tmp);
    }
}

//Cursor
template <class Item>
void    CLL<Item>::CursorFirst(){
    setCursor(getFirst());
}

template <class Item>
void    CLL<Item>::CursorLast(){
    setCursor(getLast());
}

template <class Item>
void    CLL<Item>::CursorNext(){
    setCursor(getCursor()->getNext());
}

//Search
template <class Item>
bool    CLL<Item>::FindIf(Item _key, bool (*cmp)(Item,Item)){
    bool found = false;

    if(!IsEmpty()){
        Node<Item>* it;
        it = getFirst();

        for(size_t i = 0; i < getLen(); i++){
            if( _key == it->getData() ){
                found = true;
                break;
            }

            it = it->getNext();
        }
    }
    return found;
}

template <class Item>
bool    CLL<Item>::Search(Item _key, bool (*cmp)(Item,Item) ){
    bool found = false;

    if(!IsEmpty()){
        Node<Item>* tmp = getCursor();
        //Guardamos la direccion de cursor
        setCursor(getFirst());
        for(size_t i = 0; i < getLen(); i++){
            if(_key == getCursor()->getData()){
                found = true;
                break;
            }

            setCursor(getCursor()->getNext());
        }
        if( !found ){
            setCursor(tmp);
        }
    }
    return found;
}

