#include "Vertex.hpp"


Vertex::Vertex(){

}

Vertex::Vertex(string _name){
	this -> name = _name;
	this -> neighbors = new DLL<Vertex>();
}

string Vertex::getName(){
	return this -> name;
}

int Vertex::getIntName(){
	return stoi(this -> name,nullptr,10);
}

int Vertex::getDistance(){
	return this -> distance;
}

void Vertex::setDistance(int _distance){
	this -> distance = _distance;
}

Vertex::Colors Vertex::getColor(){
	return this -> color;
}

void Vertex::setColor(Colors _color){
	this -> color = _color;
}

string Vertex::getPredecesor(){
	return this -> predecesor;
}

void Vertex::setPredecesor(string _predecesor){
	this -> predecesor = _predecesor;
}

int Vertex::getWeight(){
	return this -> weigth;
}

DLL<Vertex> *Vertex::getNeighbors(){
	return this -> neighbors;
}

void Vertex::setFinishTime(int _time){
	this -> finish_time = _time;
}

int Vertex::getFinishTime(){
	return this -> finish_time;
}

void Vertex::setDiscoveryTime(int _time){
	this -> discovery_time = _time;
}

int Vertex::getDiscoveryTime(){
	return this -> discovery_time;
}

void Vertex::addNeighbors(Vertex v){
	this -> neighbors -> InsertBack(v);
}

void Vertex::print(){
	string color = "";

	switch(this -> color){
		case Colors::BLACK: color = "BLACK"; break;
		case Colors::GRAY: color = "GRAY"; break;
		case Colors::WHITE: color = "WHITE"; break;
	}

	cout << this -> getName() << "-> " << this -> getPredecesor()
	     << "  " << this -> getDistance() << "  " << this -> getDiscoveryTime() 
	     << "/" << this -> getFinishTime() << "  " << "\t" << color;
}