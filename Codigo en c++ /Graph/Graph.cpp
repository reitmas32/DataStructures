#include "Graph.hpp"

size_t Graph::hash_string(string key, size_t max){
	const char *newKey = key.c_str();
	int length = strlen(newKey);

	int i,sum;

	for(sum =0, i=0; i< length; i++){
		sum += newKey[i];
	}

	return sum %max;
}
size_t Graph::coll_res( size_t index, size_t max ){
	 size_t new_index = (index + 1) % max;
	 return new_index;
}
#if 1
void Graph::printVertex(string name, Vertex vertex){
	vertex.print();
	cout << endl;
}
#endif

//===========================================================

Graph::Graph(size_t capacity){
	Vertex null;
	this -> vertices = new Map<string,Vertex>(capacity,"",hash_string,coll_res);
}

Graph::~Graph(){
	delete this -> vertices;
}

bool Graph::contains(string name){
	Vertex tmp;

	return this ->vertices -> Retrieve(name,&tmp);
}

bool Graph::addVertex(Vertex v){

	return (this -> vertices -> Insert(v.getName(),v));
}

bool Graph::addEdge(string b1, string b2){

	Vertex v1(b1);
	Vertex v2(b2);

	if(this -> vertices -> Retrieve(b1,&v1) && this -> vertices -> Retrieve(b2,&v2)){
		if(v1.addNeighbors(v2) && v2.addNeighbors(v1)){
			this -> vertices -> Remove(b1);
			this -> vertices -> Remove(b2);
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

	if(this -> vertices -> Retrieve(b1,&v1) && this -> vertices -> Retrieve(b2,&v2)){
		if(v1.addNeighbors(v2)){
			this -> vertices -> Remove(b1);
			this -> addVertex(v1);
			return true;	
		}
	}

	return false;

}

Vertex Graph::getVertex(string v){
	Vertex vertex(v);

	this -> vertices -> Retrieve(v,&vertex);

	return vertex;
}

Map<string,Vertex>  *Graph::getMap(){
	return this -> vertices;
}

void Graph::print(){
	cout << endl;
	this -> vertices -> Iterator(printVertex);
}
#if 0
Stack<string> Graph::DIJKSTRA(Vertex start, Vertex end){
	
}
#endif

