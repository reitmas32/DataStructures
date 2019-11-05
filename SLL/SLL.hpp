/**
  * @file    SLL.cpp
  * @version 2.0
  * @date    14/07/2019
  * @author  Zamora Ramírez Oswaldo Rafael
  * @brief   API de una SLL de tipos dinamicos
*/

#ifndef SLL_SLL_HPP
#define SLL_SLL_HPP

#include "Node.hpp"
#include "Node.cpp"

template <class Item>
class SLL{
private:
    Node<Item>* first;
    Node<Item>* last;
    Node<Item>* cursor;
    size_t      len{};

    //Getters
    Node<Item>* getFirst(){return first;}
    Node<Item>* getLast(){return last;}
    Node<Item>* getCursor(){return cursor;}
    size_t      getLen(){return len;}

    //Setters
    void        setFirst(Node<Item>* _first){first = _first;}
    void        setLast(Node<Item>* _last){last = _last;}
    void        setCursor(Node<Item>* _cursor){cursor = _cursor;}
    void        setLen(size_t _len){len = _len;}

    //Up and Down
    void        lenUp(){++len;}
    void        lenDown(){--len;}
public:

    //Constructor
    SLL();

    //Destructor
    ~SLL();

    //Insert
    bool   InsertBack(  Item _data );
    bool   InsertAfter( Item _data );
    bool   InsertFront( Item _data );

    //Remove
    bool   RemoveFront(Item* _data_back );

    //Peek
    bool   Peek(Item* _data_back );

    //Otros
    size_t Len();
    bool   IsEmpty();
    void   MakeEmpty();

    //Cursor
    void   CursorFirst();
    void   CursorLast();
    void   CursorNext();

    //Search
    bool   FindIf(Item _key, bool (*cmp)(Item,Item));
    bool   Search(Item _key, bool (*cmp)(Item,Item));

};

#endif //SLL_SLL_HPP
