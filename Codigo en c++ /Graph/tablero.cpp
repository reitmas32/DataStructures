#include <iostream>
#include "Graph.hpp"


using namespace std;

#define TAM 64

int main(){

	Graph tablero(65);
#if 1
	string letras[TAM] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","Ñ","O","P","Q","R","S","T","U","V","W","X","Y","Z"
					   ,"A1","B1","C1","D1","E1","F1","G1","H1","I1","J1","K1","L1","M1","N1","Ñ1","O1","P1","Q1","R1","S1","T1","U1","V1","W1","X1","Y1","Z1"
					   ,"A2","B2","C2","D2","E2","F2","G2","H2","I2","J2"};

#endif	
	for(size_t i = 0; i<TAM; i++){
		tablero.addVertex(Vertex(letras[i]));
	}

	tablero.print();


	return 0;
}