/**
  * @file    DLL.cpp
  * @version 2.0
  * @date    17/07/2019
  * @author  Zamora Ramírez Oswaldo Rafael
  * @brief   API de una DLL de tipos dinamicos
*/

#include "DLL.hpp"

template <class Item>
DLL<Item>::DLL(){
    setFirst(NULL);
    setLast(NULL);
    setCursor(NULL);
    setLen(0);
}

template <class Item>
DLL<Item>::~DLL(){
    this ->MekeEmpty();
    free(this);
}

//Insert
template <class Item>
bool DLL<Item>::InsertFront(Item _data) {
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
            getFirst()->setPrev(n);
            setFirst(n);
        }
        lenUp();
    }
    return done;
}

template <class Item>
bool DLL<Item>::InsertBack(Item _data) {
    bool done = false;
    auto* n = new Node<Item>(_data);
    if(n){
        done = true;

        if(IsEmpty()){
            setFirst(n);
            setLast(n);
        }
        else{
            n->setPrev(getLast());
            getLast()->setNext(n);
            setLast(n);
        }
        lenUp();
    }
    return done;
}

template <class Item>
bool DLL<Item>::InsertAfter(Item _data) {
    bool done = false;
    if(getCursor()!=NULL){
        if(getCursor()==getLast()){
            InsertBack(_data);
        }
        else{
            auto* n = new Node<Item>(_data);
            if(n){
                done = true;
                n->setPrev(getCursor());
                n->setNext(getCursor()->getNext());
                getCursor()->setNext(n);
                getCursor()->getNext()->setPrev(n);
                lenUp();
            }
        }
    }
    return done;
}

template <class Item>
bool DLL<Item>::InsertBefore(Item _data) {
    bool done = false;
    if(getCursor()!=NULL){
        if(getCursor()==getFirst()){
            InsertFront(_data);
        }
        else{
            auto* n = new Node<Item>(_data);
            if(n){
                done = true;
                n->setNext(getCursor());
                n->setPrev(getCursor()->getPrev());
                getCursor()->setPrev(n);
                getCursor()->getPrev()->setNext(n);
                lenUp();
            }
        }
    }
    return done;
}

//Remove
template <class Item>
bool DLL<Item>::Remove(Item* _data_back){
    bool done = false;
    if(getCursor() != NULL){
        if(getCursor()==getFirst()){
            RemoveFront(_data_back);
        }
        else if(getCursor()==getLast()){
            RemoveBack(_data_back);
        }
        else{
            done = true;
            *_data_back = getCursor()->getData();
            Node<Item>* tmp;
            tmp=getCursor();
            getCursor()->getPrev()->setNext(getCursor()->getNext());
            getCursor()->getNext()->setPrev(getCursor()->getPrev());
            tmp->~Node();
        }
        lenDown();
    }
    return done;
}

template <class Item>
bool DLL<Item>::RemoveFront(Item* _data_back){
    bool done = false;
    if(!IsEmpty()){
        done = true;
        *_data_back = getFirst()->getData();
        Node<Item>* tmp;
        tmp=getFirst()->getNext();
        if(getLen()==1){
            getFirst()->~Node();
            getLast()->~Node();
        }
        else{
            getFirst()->~Node();
        }
        setFirst(tmp);
        lenDown();
    }
    return done;
}

template <class Item>
bool DLL<Item>::RemoveBack(Item* _data_back){
    bool done = false;
    if(!IsEmpty()){
        done = true;
        *_data_back = getLast()->getData();
        Node<Item>* tmp;
        tmp=getLast()->getPrev();
        if(getLen()==1){
            getFirst()->~Node();
            getLast()->~Node();
        }
        else{
            getLast()->~Node();
        }
        setLast(tmp);
        lenDown();
    }
    return done;
}

template <class Item>
bool DLL<Item>::RemoveAfter(Item* _data_back){
    bool done = false;
    if(getCursor()->getNext() != NULL){
        done = true;
        *_data_back = getCursor()->getNext()->getData();
        Node<Item>* tmp;
        tmp=getCursor()->getNext();
        getCursor()->getNext()->getNext()->setPrev(getCursor());
        getCursor()->setNext(getCursor()->getNext()->getNext());
        tmp->~Node();
        lenDown();
    }
    return done;
}

template <class Item>
bool DLL<Item>::RemoveBefore(Item* _data_back){
    bool done = false;
    if(getCursor()->getNext() != NULL){
        done = true;
        *_data_back = getCursor()->getPrev()->getData();
        Node<Item>* tmp;
        tmp=getCursor()->getPrev();
        getCursor()->getPrev()->getPrev()->setNext(getCursor());
        getCursor()->setPrev(getCursor()->getPrev()->getPrev());
        tmp->~Node();
        lenDown();
    }
    return done;
}

//Peek
template <class Item>
bool DLL<Item>::Peek(Item* _data_back){
    bool done = false;
    if(getCursor() != NULL){
        done = true;
        *_data_back = getCursor()->getData();
    }
    return done;
}

//Cursor
template <class Item>
void DLL<Item>::CursorFirst(){
    setCursor(getFirst());
}

template <class Item>
void DLL<Item>::CursorLast(){
    setCursor(getLast());
}

template <class Item>
void DLL<Item>::CursorNext(){
    setCursor(getCursor()->getNext());
}

template <class Item>
void DLL<Item>::CursorPrev(){
    setCursor(getCursor()->getPrev());
}

//Empty
template <class Item>
void DLL<Item>::MakeEmpty(){
    Item tmp;
    while(1){
        if(!IsEmpty()){
            RemoveBack(&tmp);
        }
        else{
            break;
        }
    }
}


//Search
template <class Item>
bool DLL<Item>::FindIf(Item _key, bool (*cmp)(Item,Item)){
    bool found = false;
    Node<Item>* tmp;
    tmp=getFirst();
    for(size_t i = 0; i < getLen(); i++){
        if(cmp(_key, tmp->getData())){
            found = true;
            break;
        }
        tmp = tmp->getNext();
    }
    return found;
}

template <class Item>
bool DLL<Item>::Search(Item _key, bool (*cmp)(Item,Item)){
    bool found = false;
    Node<Item>* tmp;
    tmp=getCursor();
    setCursor(getFirst());
    for(size_t i = 0; i < getLen(); i++){
        if(cmp(_key, getCursor()->getData())){
            found = true;
            break;
        }
        CursorNext();
    }
    if(!found){
        setCursor(tmp);
    }
    return found;
}

//Traverse
template<class Item>
void DLL<Item>::TraverseBool(bool (*func)(Item)){
    Node<Item>* tmp;
    tmp=getFirst();
    for(size_t i = 0; i < getLen(); i++){
        func(tmp->getData());
        tmp = tmp->getNext();
    }
    tmp->~Node();
}

template<class Item>
void DLL<Item>::TraverseVoid(void (*func)(Item)){
    Node<Item>* tmp;
    tmp=getFirst();
    for(size_t i = 0; i < getLen(); i++){
        func(tmp->getData());
        tmp = tmp->getNext();
    }
    tmp->~Node();
}