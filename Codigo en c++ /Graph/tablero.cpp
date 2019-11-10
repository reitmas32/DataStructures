#include <iostream>
#include "Graph.hpp"


using namespace std;

#define TAM 64

int main(){

	Graph tablero(300);
#if 1
	string letras[TAM] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","Ñ","O","P","Q","R","S","T","U","V","W","X","Y","Z"
					   ,"A1","B1","C1","D1","E1","F1","G1","H1","I1","J1","K1","L1","M1","N1","Ñ1","O1","P1","Q1","R1","S1","T1","U1","V1","W1","X1","Y1","Z1"
					   ,"A2","B2","C2","D2","E2","F2","G2","H3","I2","J2"};

#endif	
	for(size_t i = 0; i<TAM; i++){
		tablero.addVertex(Vertex(letras[i]));
	}

	tablero.addEdge("A","B");
	tablero.addEdge("B","C");
	tablero.addEdge("D","E");
	tablero.addEdge("E","F");
	tablero.addEdge("A","G");
	tablero.addEdge("B","H");
	tablero.addEdge("C","J");
	tablero.addEdge("D","K");
	tablero.addEdge("E","M");
	tablero.addEdge("F","N");
	tablero.addEdge("G","H");
	tablero.addEdge("H","I");
	tablero.addEdge("I","J");	
	tablero.addEdge("J","K");
	tablero.addEdge("K","L");
	tablero.addEdge("L","M");
	tablero.addEdge("M","N");
	tablero.addEdge("G","Ñ");
	tablero.addEdge("H","O");
	tablero.addEdge("I","P");
	tablero.addEdge("L","S");
	tablero.addEdge("M","T");
	tablero.addEdge("N","U");
	tablero.addEdge("Ñ","O");
	tablero.addEdge("P","Q");	
	tablero.addEdge("R","S");
	tablero.addEdge("T","U");
	tablero.addEdge("O","Z");
	tablero.addEdge("Q","W");
	tablero.addEdge("R","X");
	tablero.addEdge("T","C1");
	tablero.addEdge("V","W");
	tablero.addEdge("W","X");
	tablero.addEdge("X","Y");
	tablero.addEdge("V","A1");
	tablero.addEdge("Y","B1");
	tablero.addEdge("Z","A1");	
	tablero.addEdge("B1","C1");
	tablero.addEdge("Z","C1");
	tablero.addEdge("Z","G1");
	tablero.addEdge("A1","D1");
	tablero.addEdge("B1","E1");
	tablero.addEdge("C1","L1");
	tablero.addEdge("D1","E1");
	tablero.addEdge("D1","H1");
	tablero.addEdge("E1","K1");
	tablero.addEdge("F1","G1");
	tablero.addEdge("G1","H1");
	tablero.addEdge("H1","I1");	
	tablero.addEdge("J1","K1");
	tablero.addEdge("K1","L1");
	tablero.addEdge("L1","M1");
	tablero.addEdge("F1","N1");
	tablero.addEdge("G1","O1");
	tablero.addEdge("I1","Q1");
	tablero.addEdge("J1","R1");
	tablero.addEdge("L1","T1");
	tablero.addEdge("M1","V1");
	tablero.addEdge("N1","Ñ1");
	tablero.addEdge("O1","P1");
	tablero.addEdge("P1","Q1");	
	tablero.addEdge("Q1","R1");
	tablero.addEdge("R1","S1");
	tablero.addEdge("S1","T1");
	tablero.addEdge("U1","V1");
	tablero.addEdge("Ñ1","X1");
	tablero.addEdge("O1","Y1");
	tablero.addEdge("P1","Z1");
	tablero.addEdge("S1","C2");
	tablero.addEdge("T1","D2");
	tablero.addEdge("U1","E2");
	tablero.addEdge("W1","X1");
	tablero.addEdge("X1","Y1");	
	tablero.addEdge("Z1","A2");
	tablero.addEdge("B2","C2");
	tablero.addEdge("D2","E2");
	tablero.addEdge("E2","F2");
	tablero.addEdge("W1","G2");
	tablero.addEdge("A2","H3");
	tablero.addEdge("B2","I2");
	tablero.addEdge("F2","J2");
	tablero.addEdge("G2","H3");
	tablero.addEdge("H3","I2");
	tablero.addEdge("I2","J2");

	tablero.print(0);
	return 0;
}