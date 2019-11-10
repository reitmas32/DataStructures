#include <iostream>
#include "Graph.hpp"

using namespace std;

#define TAM 64

int main(){

	Graph tablero(TAM);
	string letras[TAM] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","Ñ","O","P","Q","R","S","T","U","V","W","X","Y","Z"
					   "AA","BA","CA","DA","EA","FA","GA","HA","IA","JA","KA","LA","MA","NA","ÑA","OA","PA","QA","RA","SA","TA","UA","VA","WA","XA","YA","ZA"
					   "AB","BB","CB","DB","EB","FB","GB","HB","IB","JB"};

	for(size_t i = 0; i<TAM; i++){
		tablero.addVertex(Vertex(letras[i]));
	}

	tablero.print();

	return 0;
}