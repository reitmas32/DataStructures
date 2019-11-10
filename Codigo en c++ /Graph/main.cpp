#include <iostream>
#include "Graph.hpp"


using namespace std;

#define TAM 7

int main(){

	Graph tablero(300);
#if 1
	string letras[TAM] = {"A","B","C","D","E","F","G"};

#endif	
	for(size_t i = 0; i<TAM; i++){
		tablero.addVertex(Vertex(letras[i]));
	}

    tablero.addEdge("A","B");
    tablero.addEdge("A","C");
    tablero.addEdge("B","D");
    tablero.addEdge("C","D");
    tablero.addEdge("C","E");
    tablero.addEdge("D","F");
    tablero.addEdge("F","E");
    tablero.addEdge("F","G");


	tablero.print(0);
	return 0;
}