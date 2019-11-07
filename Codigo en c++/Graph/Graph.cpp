#include "Graph.hpp"

bool Graph::compareCouple(Couple <string,Vertex> c1, Couple <string,Vertex> c2){

	if(c1.getOne() == c2.getOne()){
		return true;
	}

	return false;
}

void Graph::printVertex(Couple <string,Vertex> couple){
	Vertex vertex = couple.getTwo();

	vertex.print();
}

Graph::Graph(){
	this -> vertices = new DLL<Couple<string, Vertex>>();
}

bool Graph::contains(string name){
	Couple<string, Vertex> tmp;

	return vertices -> FindIf(tmp,compareCouple);
}

bool Graph::addVertex(Vertex v){
	Couple<string, Vertex> tmp;

	tmp.setOne(v.getName());
	tmp.setTwo(v);

	return (this -> vertices -> InsertBack(tmp));
}

bool Graph::addEdge(string b1, string b2){

	Vertex v1(b1);
	Vertex v2(b2);

	Couple<string, Vertex> couple1(b1,v1);
	Couple<string, Vertex> couple2(b2,v2);


	if(this -> vertices -> Remove(&couple1) && this -> vertices -> Remove(&couple2)){
		if(v1.addNeighbors(v2) && v2.addNeighbors(v1)){
			this -> addVertex(v1);
			this -> addVertex(v2);
			return true;	
		}
	}

	return false;
}
bool Graph::addEdgeDirected(string b1, string b2){

	Vertex v1(b1);
	Vertex v2(b2);
	Couple<string, Vertex> couple(b1,v1);

	if(this -> vertices -> Remove(&couple)){
		if(v1.addNeighbors(v2)){
			this -> addVertex(v1);
			return true;	
		}
	}

	return false;
}

Vertex Graph::getVertex(string v){
	Couple<string, Vertex> tmp(v,(Vertex){"tmp"});

	this -> vertices -> Search(tmp,compareCouple);
	this -> vertices -> Peek(&tmp);

	return tmp.getTwo();
}

DLL<Couple<string, Vertex>> *Graph::getMap(){
	return this -> vertices;
}

void Graph::print(){
	cout << endl;
	this -> vertices -> TraverseVoid(printVertex);
}
void Graph::BSF(Vertex start){
	for(size_t i =0; i< this -> vertices -> Len(); i++){
		
	}
}
void Graph::DFS(Vertex start);
void Graph::dfsTraverse(Vertex v);
void Graph::updateColor(Stack<string> stack);
void Graph::goToVertex(string _v1, string _v2);


