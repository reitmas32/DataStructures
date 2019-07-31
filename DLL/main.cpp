#include <iostream>

#include "Node.hpp"

using namespace std;

//--------------------------------------------------------------------
//                          Driver Program
//--------------------------------------------------------------------

int main(void){

    Node<int> miNode(3);

    cout<<miNode.GetData();

    return 0;
}