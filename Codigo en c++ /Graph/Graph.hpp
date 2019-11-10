#ifndef GRAPH_HPP
#define GRAPH_HPP
#include <iostream>
#include "../Stack/Stack.hpp"
#include "../Vertex/Vertex.hpp"
#include "../Map/Map.hpp"
#include <string.h>

using namespace std;



class Graph{
	private:
		Map<string,Vertex> *vertices;
		static int time;
		void gotoVertex(Vertex v1, string _v2, Stack<string> stack);
		static size_t hash_string(string key, size_t max);
		static void printNeighbors(string name, Vertex vertex);
		static void printVertex(string name, Vertex vertex);
		static size_t coll_res( size_t index, size_t max );
	public: 
		Graph(size_t capacity);
		~Graph();
		bool contains(string name);
		bool addVertex(Vertex v);
		bool addEdge(string b1, string b2);
		bool addEdgeDirected(string b1, string b2);
		Vertex getVertex(string v);
		Map<string,Vertex> *getMap();
		void print(size_t modo);
		Stack<string> DIJKSTRA(Vertex start, Vertex end);
};


#endif
