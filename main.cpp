#include <iostream>
#include <vector>
#include <fstream>
#include "Vertex.h"

using namespace std;

struct Node
{
	int ID;
	Node *nextNode = NULL;
};

int main(int argc, char const *argv[])
{
	string inputFile = argv[1];
	string outputFile = argv[2];

	ifstream infile;
	infile.open(inputFile);

	//you may need to move this to the end just to reduce the time.
	ofstream outfile;
	outfile.open(outputFile);

	int nOfVertexes;
	infile >> nOfVertexes;

	vector<Vertex> vertexes(nOfVertexes);

	int nOfEdges = 0;

	for (int i = 0; i < nOfVertexes; i++)
	{
		int id, outDegree;
		infile >> id;
		infile >> outDegree;
		vertexes[id].outdegree = outDegree;
		for (int i = 0; i < outDegree; i++)
		{
			int adjacent;
			infile >> adjacent;
			vertexes[id].addOutgoingEdge(adjacent);
			nOfEdges++;
			vertexes[adjacent].indegree++;
		}
	}

	int startingIndex;
	infile >> startingIndex;

	bool isEulerian = true;

	for (int i = 0; i < nOfVertexes; i++)
	{
		if (vertexes[i].indegree != vertexes[i].outdegree)
		{
			isEulerian = false;
			break;
		}
	}

	if (!isEulerian)
	{
		outfile << "no path";
	}
	else
	{
		Node *first = new Node();
		first->ID = startingIndex;
		int eulerianLength = 1;
		int index = startingIndex;
		Node *eulerianCircuit = first;
		while (eulerianLength <= nOfEdges)
		{
			Node *tour = new Node();
			Node *temp = tour;

			int mergingNodeLength = 0;
			while (!vertexes[index].outgoingEdgeList.front()->isVisited)
			{
				Edge *visitingEdge = vertexes[index].outgoingEdgeList.front(); //should delete this
				visitingEdge->isVisited = true;
				vertexes[index].outgoingEdgeList.pop();
				vertexes[index].outgoingEdgeList.push(visitingEdge);
				temp->nextNode = new Node();
				temp = temp->nextNode;
				index = visitingEdge->end;
				temp->ID = index;
				mergingNodeLength++;
			}

			temp->nextNode = eulerianCircuit->nextNode;
			eulerianCircuit->nextNode = tour->nextNode;
			eulerianLength += mergingNodeLength;

			Node *traverse = first; //this may be eulerian
			while (traverse->nextNode != NULL)
			{
				if (!vertexes[traverse->ID].outgoingEdgeList.front()->isVisited)
				{
					eulerianCircuit = traverse;
					index = traverse->ID;
					break;
				}
				traverse = traverse->nextNode;
			}
			delete tour;
			//delete temp; 	
		}

		Node* output = first;
		while (output != NULL)
		{
			outfile << output->ID << " ";
			//outfile << sil->ID << " ";
			Node* sil  = output->nextNode;
			delete output;
			//output = output->nextNode;
			output = sil;
		}

		/*while (output != NULL)
		{
			outfile << output->ID << " ";
			output = output->nextNode;
		}*/

		//delete first;
	}

	return 0;
}