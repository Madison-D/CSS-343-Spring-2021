//---------------------------------------------------------------------------
// Graph.cpp
// Member function definitions for class Graph
// Author:  Madison Dienhart
//---------------------------------------------------------------------------
// Graph class: This class implements Dijkstra's algorithm using a priority
// queue and prints the values to a table. It is capable of printing out
// values with a specific source and destination or printing all paths.
// To do this it reads data from a file, inserts using
// an adjacency list to store the edges, it then finds all shortest paths
// using a priority queue.
//---------------------------------------------------------------------------

#include <fstream>
#include "Graph.h"
using namespace std;

#include <queue>
#include <iomanip>
# define INF 0x3f3f3f3f

//-------------------------- Constructor ------------------------------------
// Default constructor for class Graph
// Preconditions:   None
// Postconditions: Sets size to 1.
Graph::Graph() {
	size = 0;
}

//---------------------------- Copy -----------------------------------------
// Copy constructor for class Graph
// Preconditions: None.
// Postconditions: init object is copied.
Graph::Graph(const Graph& init) {

}

//---------------------------- Destructor -----------------------------------
// Destructor for class Graph
// Preconditions: None
// Postconditions:  Clears all memory allocated for Graph.
// commented out due to errors.
Graph::~Graph() {
	//clearAll();
}

//----------------------------- clearAll -------------------------------------
// Method that clears all memory. I experienced error here, I commented out
// code.
// Preconditions: all Vertex data, all EdgeNode data.
// Postconditions: Is intended to delete all data in the vertices
// then delete all edgeNodes, and nodes attached.
void Graph::clearAll()  {
	for (int i = 0; i < size; i++) {
			delete vertices[i].data;
	}

	/*	for (int i = 0; i < size; i++) {
		while (vertices[i].edgeHead != nullptr) {
			delete vertices[i].data;
		}

	EdgeNode* temp = vertices[i].edgeHead;
		while (temp != nullptr) {
			temp = temp->nextEdge;
			temp->nextEdge = nullptr;
			delete temp;
		}
	}*/
}

//-------------------------------- buildGraph ---------------------------------
// Builds a graph by reading data from an ifstream
// Preconditions:  infile has been successfully opened and the file contains
//                 properly formated data (according to the program specs)
// Postconditions: One graph is read from infile and stored in the object
void Graph::buildGraph(ifstream& infile) {

	infile >> size;						// data member stores array size
	if (infile.eof())
		return;
	infile.ignore();					// throw away '\n' to go to next line

	// get descriptions of vertices
	for (int v = 1; v <= size; v++) {
		vertices[v].data = new Vertex;
		infile >> *vertices[v].data;	// use Vertex::operator>> to read descriptions
	}

	// fill cost edge array
	int src = 1, dest = 1, weight = 1;
	for (;;) {
		infile >> src >> dest >> weight;
		if (src == 0 || infile.eof())
			break;
		insertEdge(src, dest, weight);
	}
}

//-----------------------------  =  -----------------------------------------
// Overloaded assignment operator to copy graph.
// Preconditions: None
// Postconditions: Identical copy of graph.
const Graph& Graph::operator=(const Graph& right) {
	return *this;
}

//-----------------------------  insertEdge  ---------------------------------
// Function to insert edge.
// Preconditions: The vertices and edge costs were read from a .txt file.
// Postconditions: The edges are inserted connected to the correct
// vertices and associated with the correct weight.
void Graph::insertEdge(int src, int dest, int weight)  {
	EdgeNode* edgeNode = new EdgeNode();
	edgeNode->weight = weight;
	edgeNode->adjVertex = dest;

	if (vertices[src].edgeHead == nullptr)
		vertices[src].edgeHead = edgeNode;

	else {

		EdgeNode* currEdge = vertices[src].edgeHead;

		while (currEdge->nextEdge != nullptr) {
			currEdge = currEdge->nextEdge;
		}

		currEdge->nextEdge = edgeNode;
	}
}

//-----------------------------  removeEdge  ---------------------------------
// Function to remove edge
// Preconditions: The edge exists with in the range of src to dest.
// Postconditions: The edge is deleted.
void Graph::removeEdge(int src, int dest)  {

	if (src < 1 || src > size || dest < 1 || dest > size)
		return;

	EdgeNode* currNode = vertices[src].edgeHead;
	EdgeNode* prevNode = nullptr;

	if (currNode != nullptr && currNode->adjVertex == dest) {
		vertices[src].edgeHead = currNode->nextEdge;
		delete currNode;
		return;
	}

	else {
		while (currNode != nullptr && currNode->adjVertex != dest) {
			prevNode = currNode;
			currNode = currNode->nextEdge;
		}

		if (currNode == nullptr)
			return;

		prevNode->nextEdge = currNode->nextEdge;

		delete currNode;
		currNode = nullptr;
	}
}

//-----------------------------  findShortestPath  ---------------------------------
// Function to find shortest path between vertices.
// Preconditions: The data has been read from a file and inserted.
// Postconditions: All paths have been found between vertices.
void Graph::findShortestPath()
{
	for (int i = 1; i <= size; i++) {
		shortestPathHelper(i);
	}
}

//-----------------------------  findShortestPathHelper  ---------------------------------
// Function to find shortest path helper priority queue.
// Preconditions: Source is passed in from findShortestPath.
// Postconditions: All paths have been found.
void Graph::shortestPathHelper(int src)  {
	priority_queue< intPair, vector <intPair>, greater<intPair> > PQ;

	vector<int> dist(size + 1, INT_MAX);

	PQ.push(make_pair(0, src));
	T[src][src].dist = 0;

	while (!PQ.empty()) {

		int nextVertex = PQ.top().second;
		PQ.pop();

		EdgeNode* node = vertices[nextVertex].edgeHead;

		while (node != nullptr)  {

			int adjVertex = node->adjVertex;
			int newCost = T[src][nextVertex].dist + node->weight;

			if (T[src][nextVertex].visited == false && T[src][adjVertex].dist >
				newCost)  {

				T[src][adjVertex].path = nextVertex;
				T[src][adjVertex].dist = newCost;
				intPair path = make_pair(newCost, node->adjVertex);
				PQ.push(path);
			}
			node = node->nextEdge;
		}
		T[src][nextVertex].visited = true;
	}
}

//-----------------------------  displayAll  ---------------------------------
// Function to display all vertices and shortest paths.
// Preconditions: All shortest paths have been found.
// Postconditions: Prints out header, src, dest, dist, and path.
// using display helper.
void Graph::displayAll()
{
	cout << "Description                  From  To    Dist  Path" << endl;

	for (int i = 1; i <= size; i++) {

		cout << endl;
		cout << *vertices[i].data << endl;

		for (int j = 1; j <= size; j++) {

			if (T[i][j].dist > 0)
				displayHelper(i, j);
		}
	}
}

//-----------------------------  display  ------------------------------------
// Function to display shortest path from a source to a destination vertex.
// Preconditions: All shortest paths have been found.
// Postconditions: Prints out shortest path from one src to one dest.
// Uses displayHelper.
void Graph::display(int src, int dest)  {
	cout << endl;
	displayHelper(src, dest);
	cout << setw(41) << *vertices[src].data << endl;
	cout << setw(41) << *vertices[T[src][dest].path].data << endl;
	cout << setw(41) << *vertices[dest].data << endl;
}

//---------------------------  displayHelper  --------------------------------
// displayHelper is a function that prints out display.
// Preconditions: src and dest passed in from display methods above.
// Postconditions: Prints out information for the table.
void Graph::displayHelper(int src, int dest)  {

	if (T[src][dest].path != 0 && T[src][dest].path != INF) {

		cout << setw(31) << src << setw(6) << dest <<
			setw(6) << T[src][dest].dist << setw(5);
		pathHelper(src, dest);
		cout << " " << dest << endl;
	}

	else
		cout << setw(31) << src << setw(6) << dest << setw(6) << "--" << endl;
}

//-----------------------------  pathHelper  ---------------------------------
//pathHelper is a function that helps to print all data for the path.
// Preconditions: Passed in values from displayHelper.
// Postconditions: Recursively prints out each path for table.
void Graph::pathHelper(int src, int dest) const  {
	if (dest != src)
		pathHelper(src, T[src][dest].path);

	if (T[src][dest].path > 0)
		cout << " " << T[src][dest].path;
}
