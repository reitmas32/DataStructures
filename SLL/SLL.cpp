/**
  * @file    SLL.cpp
  * @version 2.0
  * @date    14/07/2019
  * @author  Zamora Ramírez Oswaldo Rafael
  * @brief   API de una SLL de tipos dinamicos
*/
#include "SLL.hpp"

//Constructor
template <class Item>
SLL<Item>::SLL(){
    setFirst(NULL);
    setCursor(NULL);
    setLast(NULL);
    setLen(0);
}

//Destructor
template <class Item>
SLL<Item>::~SLL(){
    MakeEmpty();
    free(this);
}

//Insert
template <class Item>
bool    SLL<Item>::InsertBack(  Item _data ){
    bool done = false;
    auto* n = new Node<Item>(_data);
    if(n){
        done = true;
        if(IsEmpty()){
            setFirst(n);
            setLast(n);
        }
        else{
            getLast()->setNext(n);
            setLast(n);
        }
        lenUp();
    }
    return done;
}

template <class Item>
bool SLL<Item>::InsertAfter( Item _data ){
    bool done = false;
    auto* n = new Node<Item>(_data);
    if(n){
        done = true;
        if(IsEmpty()){
            setFirst(n);
            setLast(n);
        }
        else{
            n->setNext(getCursor()->getNext());
            getCursor()->setNext(n);
        }
        lenUp();
    }
    return done;
}

template <class Item>
bool    SLL<Item>::InsertFront( Item _data ){
    bool done = false;
    auto* n = new Node<Item>(_data);
    if(n){
        done = true;
        if(IsEmpty()){
            setFirst(n);
            setLast(n);
        }
        else{
            n->setNext(getFirst());
            setFirst(n);
        }
        lenUp();
    }
    return done;
}

//Remove
template <class Item>
bool    SLL<Item>::RemoveFront(Item* _data_back ){
    bool done = false;
    if(!IsEmpty()){
        done = true;
        *_data_back = getFirst()->getData();
        Node<Item>* tmp = getFirst();
        getFirst()->~Node();
        setFirst(tmp);
        lenDown();
    }
    return done;
}

//Peek
template <class Item>
bool    SLL<Item>::Peek(Item* _data_back ){
    bool done = false;
    if(!IsEmpty() && getCursor()!=NULL){
        done = true;
        *_data_back = getCursor()->getData();
    }
    return done;
}

//Otros
template <class Item>
size_t  SLL<Item>::Len(){
    return getLen();
}

template <class Item>
bool    SLL<Item>::IsEmpty(){
    return getLen() == 0;
}

template <class Item>
void    SLL<Item>::MakeEmpty(){
    Item tmp;
    while (!IsEmpty()){
        RemoveFront(&tmp);
    }
}

//Cursor
template <class Item>
void    SLL<Item>::CursorFirst(){
    setCursor(getFirst());
}

template <class Item>
void    SLL<Item>::CursorLast(){
    setCursor(getLast());
}

template <class Item>
void    SLL<Item>::CursorNext(){
    setCursor(getCursor()->getNext());
}

//Search
template <class Item>
bool    SLL<Item>::FindIf(Item _key, bool (*cmp)(Item,Item)){
    bool found = false;

    if(!IsEmpty()){
        Node<Item>* it;
        it = getFirst();

        do{
            if( _key == it->getData() ){
                found = true;
                break;
            }

            it = it->getNext();
        }while(it->getNext() != NULL);
    }
    return found;
}

template <class Item>
bool    SLL<Item>::Search(Item _key, bool (*cmp)(Item,Item) ){
    bool found = false;

    if(!IsEmpty()){
        Node<Item>* tmp = getCursor();
        //Guardamos la direccion de cursor
        setCursor(getFirst());
        do{
            if(_key == getCursor()->getData()){
                found = true;
                break;
            }
            setCursor(getCursor()->getNext());
        }while(getCursor()->getNext() != NULL);
        if( !found ){
            setCursor(tmp);
        }
    }
    return found;
}

