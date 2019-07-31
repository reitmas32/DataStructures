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
    SetFirst(NULL);
    SetLast(NULL);
    SetCursor(NULL);
    SetLen(0);
}

template <class Item>
DLL<Item>::~DLL(){
    //MekeEmpty();
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
            SetFirst(n);
            SetLast(n);
        }
        else{
            n->SetNext(GetFirst());
            GetFirst()->SetPrev(n);
            SetFirst(n);
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
            SetFirst(n);
            SetLast(n);
        }
        else{
            n->SetPrev(GetLast());
            GetLast()->SetNext(n);
            SetLast(n);
        }
        lenUp();
    }
    return done;
}

template <class Item>
bool DLL<Item>::InsertAfter(Item _data) {
    bool done = false;
    if(GetCursor()!=NULL){
        if(GetCursor()==GetLast()){
            InsertBack(_data);
        }
        else{
            auto* n = new Node<Item>(_data);
            if(n){
                done = true;
                n->SetPrev(GetCursor());
                n->SetNext(GetCursor()->GetNext());
                GetCursor()->SetNext(n);
                GetCursor()->GetNext()->SetPrev(n);
                lenUp();
            }
        }
    }
    return done;
}

template <class Item>
bool DLL<Item>::InsertBefore(Item _data) {
    bool done = false;
    if(GetCursor()!=NULL){
        if(GetCursor()==GetFirst()){
            InsertFront(_data);
        }
        else{
            auto* n = new Node<Item>(_data);
            if(n){
                done = true;
                n->SetNext(GetCursor());
                n->SetPrev(GetCursor()->GetPrev());
                GetCursor()->SetPrev(n);
                GetCursor()->GetPrev()->SetNext(n);
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
    if(GetCursor() != NULL){
        if(GetCursor()==GetFirst()){
            RemoveFront(_data_back);
        }
        else if(GetCursor()==GetLast()){
            RemoveBack(_data_back);
        }
        else{
            done = true;
            *_data_back = GetCursor()->GetData();
            Node<Item>* tmp;
            tmp=GetCursor();
            GetCursor()->GetPrev()->SetNext(GetCursor()->GetNext());
            GetCursor()->GetNext()->SetPrev(GetCursor()->GetPrev());
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
        *_data_back = GetFirst()->GetData();
        Node<Item>* tmp;
        tmp=GetFirst()->GetNext();
        if(GetLen()==1){
            GetFirst()->~Node();
            GetLast()->~Node();
        }
        else{
            GetFirst()->~Node();
        }
        SetFirst(tmp);
        lenDown();
    }
    return done;
}

template <class Item>
bool DLL<Item>::RemoveBack(Item* _data_back){
    bool done = false;
    if(!IsEmpty()){
        done = true;
        *_data_back = GetLast()->GetData();
        Node<Item>* tmp;
        tmp=GetLast()->GetPrev();
        if(GetLen()==1){
            GetFirst()->~Node();
            GetLast()->~Node();
        }
        else{
            GetLast()->~Node();
        }
        SetLast(tmp);
        lenDown();
    }
    return done;
}

template <class Item>
bool DLL<Item>::RemoveAfter(Item* _data_back){
    bool done = false;
    if(GetCursor()->GetNext() != NULL){
        done = true;
        *_data_back = GetCursor()->GetNext()->GetData();
        Node<Item>* tmp;
        tmp=GetCursor()->GetNext();
        GetCursor()->GetNext()->GetNext()->SetPrev(GetCursor());
        GetCursor()->SetNext(GetCursor()->GetNext()->GetNext());
        tmp->~Node();
        lenDown();
    }
    return done;
}

template <class Item>
bool DLL<Item>::RemoveBefore(Item* _data_back){
    bool done = false;
    if(GetCursor()->GetNext() != NULL){
        done = true;
        *_data_back = GetCursor()->GetPrev()->GetData();
        Node<Item>* tmp;
        tmp=GetCursor()->GetPrev();
        GetCursor()->GetPrev()->GetPrev()->SetNext(GetCursor());
        GetCursor()->SetPrev(GetCursor()->GetPrev()->GetPrev());
        tmp->~Node();
        lenDown();
    }
    return done;
}

//Peek
template <class Item>
bool DLL<Item>::Peek(Item* _data_back){
    bool done = false;
    if(GetCursor() != NULL){
        done = true;
        *_data_back = GetCursor()->GetData();
    }
    return done;
}

//Cursor
template <class Item>
void DLL<Item>::CursorFirst(){
    SetCursor(GetFirst());
}

template <class Item>
void DLL<Item>::CursorLast(){
    SetCursor(GetLast());
}

template <class Item>
void DLL<Item>::CursorNext(){
    SetCursor(GetCursor()->GetNext());
}

template <class Item>
void DLL<Item>::CursorPrev(){
    SetCursor(GetCursor()->GetPrev());
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
    tmp=GetFirst();
    for(size_t i = 0; i < GetLen(); i++){
        if(cmp(_key, tmp->GetData())){
            found = true;
            break;
        }
        tmp = tmp->GetNext();
    }
    return found;
}

template <class Item>
bool DLL<Item>::Search(Item _key, bool (*cmp)(Item,Item)){
    bool found = false;
    Node<Item>* tmp;
    tmp=GetCursor();
    SetCursor(GetFirst());
    for(size_t i = 0; i < GetLen(); i++){
        if(cmp(_key, GetCursor()->GetData())){
            found = true;
            break;
        }
        CursorNext();
    }
    if(!found){
        SetCursor(tmp);
    }
    return found;
}

//Traverse
template<class Item>
void DLL<Item>::TraverseBool(bool (*func)(Item)){
    Node<Item>* tmp;
    tmp=GetFirst();
    for(size_t i = 0; i < GetLen(); i++){
        func(tmp->GetData());
        tmp = tmp->GetNext();
    }
    tmp->~Node();
}

template<class Item>
void DLL<Item>::TraverseVoid(void (*func)(Item)){
    Node<Item>* tmp;
    tmp=GetFirst();
    for(size_t i = 0; i < GetLen(); i++){
        func(tmp->GetData());
        tmp = tmp->GetNext();
    }
    tmp->~Node();
}