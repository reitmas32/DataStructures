/**
 * @file    Stack.hpp
 * @version 1.0
 * @date    13/07/2019.
 * @author  Zamora Ramírez Oswaldo Rafael
 * @brief   Es la API de una Stack plantilla
 * @code
 
    #include <iostream>

    #include "Stack.hpp"
    #include "Stack.cpp"

    using namespace std;

    int main() {

        Stack<int> miStack(5);
        miStack.Push(10);
        int numero;
        miStack.Pop(&numero);
        cout<<numero<<endl;

        Stack<string> cadena(3);
        cadena.Push("hola");
        string palabra;
        cadena.Peek(&palabra);
        cout<<palabra<<endl;
        
        return 0;
    }
 * @endcode 
 */

#ifndef STACK_STACK_HPP
#define STACK_STACK_HPP

//Biblioteca para el uso de size_t
#include <cstddef>
//Clase plantilla en de la Stack
template <class Item>
class Stack{
private:
    //Atributos
    Item* stack;
    size_t top;
    size_t capacity;

    
    Item* getStack(){return stack;}
    size_t getTop(){return top;}
    size_t getCapacity(){return capacity;}

    //Setters
    void setStack(Item* _stack){stack = _stack;}
    void setTop(size_t _top){top = _top;}
    void setCapacity(size_t _capacity){capacity = _capacity;}
public:
    //Constructor
    Stack(size_t _capacity);

    //Destructor
    ~Stack();

    //Metodos
    bool Push(Item _data);
    bool Pop(Item* _data_back);
    bool Peek(Item* _data_back);
    size_t Len();
    size_t Capcity();
    bool IsEmpty();
    void MakeEmpty();
};

#endif //STACK_STACK_HPP
