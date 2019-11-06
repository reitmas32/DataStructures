#include "Graph.hpp"

size_t Graph::hash(string key, size_t max ){
	return stoi(key,nullptr,10) % max;
}

Graph::Graph(){
	this -> vertices = new Map<string,Vertex>(50,0L,this -> hash);
}

bool Graph::contains(string name){
	Vertex tmp;
	return vertices -> Retrieve(name,&tmp);
}

bool Graph::addVertex(Vertex v){
	return (this -> vertices -> Insert(v.getName(),v));
}

bool Graph::addEdge(string b1, string b2){
	Entry tmp;
	Vertex v1 = this -> vertices.Retrieve(b1,&tmp.value);
}
bool Graph::addEdgeDirected(string b1, string b2);
Vertex Graph::getVertex(string v);
Vertex Graph::getVertex(int v);
Map<string,Vertex> Graph::getMap();
void Graph::print();
void Graph::BSF(Vertex start);
void Graph::DFS(Vertex start);
void Graph::dfsTraverse(Vertex v);
void Graph::updateColor(Stack<string> stack);
void Graph::goToVertex(string _v1, string _v2);


