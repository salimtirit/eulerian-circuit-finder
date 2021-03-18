#include <iostream>
#include <queue>
using namespace std;

struct Edge
{
	int end = - 1;
	bool isVisited = false;
};

#ifndef Vertex_H
#define Vertex_H

class Vertex
{
public:
    Vertex();
    queue<Edge*> outgoingEdgeList;
    int indegree;
    int outdegree; // is it better to tkae this info after creating the adjList or during creation?

    void addOutgoingEdge(int adjacent);
    ~Vertex();

};

#endif