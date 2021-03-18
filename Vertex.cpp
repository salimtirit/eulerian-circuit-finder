#include <iostream>
#include <vector>
#include "Vertex.h"

Vertex::Vertex(){
    this->indegree = 0;
    this->outdegree = 0;
}

void Vertex::addOutgoingEdge(int adjacent){
    Edge* outEdge = new Edge();
    outEdge->end = adjacent;
    this->outgoingEdgeList.push(outEdge);
   //	delete outEdge;
}

Vertex::~Vertex(){
	int i = this->outgoingEdgeList.size();
	for(int j = 0; j < i ;j++){
		delete this->outgoingEdgeList.front();
		this->outgoingEdgeList.pop();
	}
}

