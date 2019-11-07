#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include "../Stack/Stack.hpp"
#include "../Vertex/Vertex.hpp"
#include "../Couple/Couple.hpp"

using namespace std;



class Graph{
	private:
		DLL<Couple<string, Vertex>> *vertices;
		static int time;
		void gotoVertex(Vertex v1, string _v2, Stack<string> stack);
		static bool compareCouple(Couple <string,Vertex> c1, Couple <string,Vertex> c2);
		static void printVertex(Couple <string,Vertex> couple);
	public: 
		Graph();
		bool contains(string name);
		bool addVertex(Vertex v);
		bool addEdge(string b1, string b2);
		bool addEdgeDirected(string b1, string b2);
		Vertex getVertex(string v);
		DLL<Couple<string, Vertex>> *getMap();
		void print();
		void BSF(Vertex start);
		void DFS(Vertex start);
		void dfsTraverse(Vertex v);
		void updateColor(Stack<string> stack);
		void goToVertex(string _v1, string _v2);
};


#endif