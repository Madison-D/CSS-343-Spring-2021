#pragma once
//---------------------------------------------------------------------------
// Header File: Graph.H
// Class: Graph
// Authors: Madison Dienhart
//---------------------------------------------------------------------------
// Graph class: This class implements Dijkstra's algorithm using a priority
// queue and prints the values to a table. It is capable of printing out
// values with a specific source and destination or printing all paths.
// To do this it reads data from a file, inserts using
// an adjacency list to store the edges, it then finds all shortest paths
// using a priority queue.
//---------------------------------------------------------------------------
#ifndef Graph_H
#define Graph_H

#include "Vertex.h"

class Graph {

typedef pair<int, int> intPair;

public:
	//-------------------------- Constructor ------------------------------------
	// Default constructor for class Graph
	// Preconditions:   None
	// Postconditions: Sets size to 1.
	Graph();

	//---------------------------- Copy -----------------------------------------
	// Copy constructor for class Graph
	// Preconditions: None.
	// Postconditions: init object is copied.
	Graph(const Graph& init);

	//---------------------------- Destructor -----------------------------------
	// Destructor for class Graph
	// Preconditions: None
	// Postconditions:  Clears all memory allocated for Graph.
	// commented out due to errors.
	~Graph();

	//-----------------------------  =  -----------------------------------------
	// Overloaded assignment operator to copy graph.
	// Preconditions: None
	// Postconditions: Identical copy of graph.
	const Graph& operator=(const Graph& right);

	//-------------------------------- buildGraph ---------------------------------
	// Builds a graph by reading data from an ifstream
	// Preconditions:  infile has been successfully opened and the file contains
	//                 properly formated data (according to the program specs)
	// Postconditions: One graph is read from infile and stored in the object
	void buildGraph(ifstream& obj);

	//-----------------------------  insertEdge  ---------------------------------
	// Function to insert edge.
	// Preconditions: The vertices and edge costs were read from a .txt file.
	// Postconditions: The edges are inserted connected to the correct
	// vertices and associated with the correct weight.
	void insertEdge(int src, int dest, int weight);

	//-----------------------------  removeEdge  ---------------------------------
	// Function to remove edge
	// Preconditions: The edge exists with in the range of src to dest.
	// Postconditions: The edge is deleted.
	void removeEdge(int src, int dest);

	//-----------------------------  findShortestPath  ---------------------------------
	// Function to find shortest path between vertices.
	// Preconditions: The data has been read from a file and inserted.
	// Postconditions: All paths have been found between vertices.
	void findShortestPath();

	//-----------------------------  displayAll  ---------------------------------
	// Function to display all vertices and shortest paths.
	// Preconditions: All shortest paths have been found.
	// Postconditions: Prints out header, src, dest, dist, and path.
	// using display helper.
	void displayAll();

	//-----------------------------  display  ------------------------------------
	// Function to display shortest path from a source to a destination vertex.
	// Preconditions: All shortest paths have been found.
	// Postconditions: Prints out shortest path from one src to one dest.
	// Uses displayHelper.
	void display(int src, int dest);

private:

	static const int MAX_VERTICES = 101;

	struct EdgeNode {
		int adjVertex = 0;			// subscript of the adjacent vertex
		int weight = 0;				// weight of edge
		EdgeNode* nextEdge = nullptr;
	};

	struct VertexNode {
		EdgeNode* edgeHead = nullptr;		// head of the list of edges
		Vertex* data = nullptr;			// store vertex data here
	};

	// array of VertexNodes
	VertexNode vertices[MAX_VERTICES]; //101

	// table of information for Dijkstra's algorithm
	struct Table {
		bool visited = false;			// whether vertex has been visited
		int dist = INT_MAX;				// shortest known distance from source
		int path = 0;				// previous vertex in path of min dist
	};

	int size;					// number of vertices in the graph

	// Table stores visited, distance, path - two dimensional in order to solve for all sources
	Table T[MAX_VERTICES][MAX_VERTICES];

	//----------------------------- clearAll -------------------------------------
	// Method that clears all memory. I experienced error here, I commented out
	// code.
	// Preconditions: all Vertex data, all EdgeNode data.
	// Postconditions: Is intended to delete all data in the vertices
	// then delete all edgeNodes, and nodes attached.
	void clearAll();

	//-----------------------------  findShortestPathHelper  ---------------------------------
	// Function to find shortest path helper priority queue.
	// Preconditions: Source is passed in from findShortestPath.
	// Postconditions: All paths have been found.
	void shortestPathHelper(int src);

	//---------------------------  displayHelper  --------------------------------
	// displayHelper is a function that prints out display.
	// Preconditions: src and dest passed in from display methods above.
	// Postconditions: Prints out information for the table.
	void displayHelper(int src, int dest);

	//-----------------------------  pathHelper  ---------------------------------
	//pathHelper is a function that helps to print all data for the path.
	// Preconditions: Passed in values from displayHelper.
	// Postconditions: Recursively prints out each path for table.
	void pathHelper(int src, int dest) const;
};

#endif

