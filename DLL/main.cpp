#include <iostream>

#include "DLL.hpp"
#include "DLL.cpp"

using namespace std;

//--------------------------------------------------------------------
//                          Driver Program
//--------------------------------------------------------------------

int main(void){

    DLL<int> miNode;

    miNode.InsertBack(5);
    int n;
    miNode.RemoveFront(&n);

    cout<<n;

    return 0;
}